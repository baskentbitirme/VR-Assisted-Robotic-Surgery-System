# Surgical Instrument Detection Model

This folder contains the object detection models used in the VR-Assisted Robotic Surgical Training Platform.

## Model Files

### best_int8.tflite
Standard INT8 quantized TensorFlow Lite model exported from YOLOv8.

### best_int8_vela.tflite
Vela-optimized model deployed on Grove Vision AI V2.

## Detected Classes

- hemostat
- kontamineKompress
- penset
- sterilKompress

## Training Pipeline

Roboflow Dataset
→ YOLOv8 Training
→ INT8 Quantization
→ TensorFlow Lite Export
→ Vela Optimization
→ Grove Vision AI V2 Deployment
