import serial
import time

porta_serial = 'COM1'

ser = serial.Serial(porta_serial, 9600)
time.sleep(2) 

with open('log_arduino.txt', 'a') as log_file:
    while True:
        if ser.in_waiting > 0:
            linha = ser.readline().decode('utf-8').strip()
            print(f"Recebido do Arduino: {linha}") 

            log_file.write(linha + '\n')

ser.close()