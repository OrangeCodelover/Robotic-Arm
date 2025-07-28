import tkinter as tk
#pip install pyserial
import serial.tools.list_ports

# Create a Window
win = tk.Tk()
win.title("Robot Arm")
win.minsize(290, 150)

motor_5_on = tk.IntVar()
motor_4_on = tk.IntVar()
motor_3_on = tk.IntVar()
motor_2_on = tk.IntVar()
motor_1_on = tk.IntVar()

motor_options = ["Motor 1", "Motor 2", "Motor 3", "Motor 4", "Motor 5"]


# Motor 5
checkbox_5 = tk.Checkbutton(win, text="Motor 5", variable=motor_5_on)
checkbox_5.grid(column=1, row=1)
rotationAngle_5 = tk.Scale(win, bd = 3, from_=0, to = 180, orient= tk.HORIZONTAL)
rotationAngle_5.grid(column=3, row=1)
tk.Label(win, text="Speed (0 to 180) ").grid(column = 4, row= 1)
# rotationAngle.pack(anchor=tk.CENTER)

# Motor 4
checkbox_4 = tk.Checkbutton(win, text="Motor 4", variable=motor_4_on)
checkbox_4.grid(column=1, row=2)
rotationAngle_4 = tk.Scale(win, bd = 3, from_=0, to = 180, orient= tk.HORIZONTAL)
rotationAngle_4.grid(column=3, row=2)
tk.Label(win, text="Speed (0 to 180) ").grid(column = 4, row= 2)

# Motor 3
checkbox_3 = tk.Checkbutton(win, text="Motor 3", variable=motor_3_on)
checkbox_3.grid(column=1, row=3)
rotationAngle_3 = tk.Scale(win, bd = 3, from_=0, to = 180, orient= tk.HORIZONTAL)
rotationAngle_3.grid(column=3, row=3)
tk.Label(win, text="Speed (0 to 180) ").grid(column = 4, row= 3)



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
    
    command = input("Select motor:  ")
    serialInst.write(command.encode('utf-8'))
    print("The motor is : ", command)
    
    
    
    if command == 'EXIT':
        exit()