-- CreateTable
CREATE TABLE "SensorData" (
    "id" SERIAL NOT NULL,
    "timestamp" TIMESTAMP(3) NOT NULL DEFAULT CURRENT_TIMESTAMP,
    "temperature" DOUBLE PRECISION NOT NULL,
    "humidity" DOUBLE PRECISION NOT NULL,
    "light" DOUBLE PRECISION NOT NULL,

    CONSTRAINT "SensorData_pkey" PRIMARY KEY ("id")
);
