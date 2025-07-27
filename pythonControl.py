#pip install pyserial
import serial.tools.list_ports

ports = serial.tools.list_ports.comports()
serialInst = serial.Serial()
portsList = []

for one in ports:
    portsList.append(str(one))
    print(str(one))
    
com = input("Select COM Port for Arduino #: ")

for i in range(len(portsList)):
    if portsList[i]. startswith("COM" + str(com)):
        use = "COM" + str(com)
        print ("The Port: ", use)
        
serialInst.baudrate = 9600
serialInst.port = use
serialInst.open()

while True:
    
    motor = input("Select motor:  ")
    serialInst.write(motor.encode('utf-8'))
    print("The motor is : ", motor)
    
    
    
    if motor == 'EXIT':
        exit()