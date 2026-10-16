const express = require('express');
const helmet = require('helmet');
const cors = require('cors');
const path = require('path');
const dotenv = require('dotenv');

dotenv.config();

const app = express();
const PORT = Number(process.env.PORT) || 3001;
const resendApiKey = process.env.RESEND_API_KEY;
const resendFromEmail = process.env.RESEND_FROM_EMAIL || 'onboarding@resend.dev';
const resendToEmail = process.env.RESEND_TO_EMAIL || 'negreiroshenrique3@gmail.com';
const allowedOrigins = (process.env.ALLOWED_ORIGINS || 'http://localhost:3001,http://127.0.0.1:3001')
  .split(',')
  .map((origin) => origin.trim())
  .filter(Boolean);

app.use(
  helmet({
    contentSecurityPolicy: {
      directives: {
        defaultSrc: ["'self'"],
        imgSrc: ["'self'", 'data:'],
        scriptSrc: ["'self'"],
        styleSrc: ["'self'", "'unsafe-inline'"],
        connectSrc: ["'self'", 'https://api.web3forms.com'],
        formAction: ["'self'", 'https://api.web3forms.com'],
        objectSrc: ["'none'"],
        frameAncestors: ["'none'"],
        baseUri: ["'self'"]
      }
    },
    crossOriginResourcePolicy: { policy: 'same-origin' },
    referrerPolicy: { policy: 'strict-origin-when-cross-origin' },
    noSniff: true
  })
);

app.use(
  cors({
    origin: (origin, callback) => {
      if (!origin || allowedOrigins.includes(origin)) {
        callback(null, true);
        return;
      }
      callback(new Error('Origem não permitida pelo CORS'));
    },
    credentials: true
  })
);

app.use(express.json({ limit: '1mb' }));
app.use(express.static(__dirname));

const sanitize = (value, max = 1000) => {
  if (typeof value !== 'string') return '';
  return value.replace(/[<>]/g, '').trim().slice(0, max);
};

app.post('/api/contact', async (req, res) => {
  try {
    const honeypot = sanitize(req.body?.website || '', 200);
    if (honeypot) {
      return res.status(400).json({ success: false, message: 'Solicitação inválida.' });
    }

    const name = sanitize(req.body?.name || '', 100);
    const email = sanitize(req.body?.email || '', 255).toLowerCase();
    const industria = sanitize(req.body?.industria || '', 200);
    const brief = sanitize(req.body?.brief || '', 1500);

    if (!name || !email || !/^[^\s@]+@[^\s@]+\.[^\s@]+$/.test(email)) {
      return res.status(400).json({ success: false, message: 'Nome e e-mail válidos são obrigatórios.' });
    }

    if (!resendApiKey || resendApiKey.includes('sua_api_key')) {
      return res.status(500).json({
        success: false,
        message: 'Configure a RESEND_API_KEY no backend para enviar e-mails.'
      });
    }

    const payload = {
      from: resendFromEmail,
      to: [resendToEmail],
      subject: `Proposta para landing page - ${name}`,
      html: `
        <h2>Nova proposta recebida</h2>
        <p><strong>Nome:</strong> ${name}</p>
        <p><strong>Email:</strong> ${email}</p>
        <p><strong>Indústria:</strong> ${industria || 'Não informada'}</p>
        <p><strong>Brief:</strong></p>
        <p>${(brief || 'Sem descrição adicional.').replace(/\n/g, '<br>')}</p>
      `
    };

    const response = await fetch('https://api.resend.com/emails', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
        Authorization: `Bearer ${resendApiKey}`
      },
      body: JSON.stringify(payload)
    });

    const result = await response.json();

    if (!response.ok) {
      return res.status(502).json({
        success: false,
        message: result?.message || 'Falha ao enviar para o Resend.'
      });
    }

    return res.status(200).json({
      success: true,
      message: 'Proposta enviada com sucesso!'
    });
  } catch (error) {
    console.error('Erro no envio do formulário:', error);
    return res.status(500).json({
      success: false,
      message: 'Erro interno ao processar a solicitação.'
    });
  }
});

app.get('*', (req, res) => {
  res.sendFile(path.join(__dirname, 'index.html'));
});

app.listen(PORT, () => {
  console.log(`Servidor rodando em http://localhost:${PORT}`);
});
