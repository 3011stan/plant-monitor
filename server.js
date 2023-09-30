const express = require('express');
const bodyParser = require('body-parser');
const { PrismaClient } = require('@prisma/client');

const prisma = new PrismaClient();
const app = express();

app.use(bodyParser.json());

// Endpoint para inserir dados do sensor
app.post('/sensor', async (req, res) => {
  const { temperature, humidity, light } = req.body;

  console.log(req.body);

  const sensorData = await prisma.sensorData.create({
    data: {
      temperature,
      humidity,
      light,
    },
  });

  res.json(sensorData);
});

app.get('/', async (req, res) => {
  const registries = await prisma.sensorData.findMany();

  res.json(registries);
});

app.listen(process.env.PORT || 3000, () => {
  console.log('Server running on http://localhost:3000');
});
