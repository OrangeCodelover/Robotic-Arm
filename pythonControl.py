import tkinter as tk
from tkinter import messagebox
#pip install pyserial
import serial
import serial.tools.list_ports

def connect_serial():
    port = selected_port.get()
    try:
        serialInst.port = port
        serialInst.open()
        messagebox.showinfo("Connection Successful", f"Connected to {port}")
    except serial.SerialException as e:
        messagebox.showerror("Connection Failed", f"Error: {e}")

# Create a Window
win = tk.Tk()
win.title("Robot Arm")
win.minsize(290, 150)

motor_5_on = tk.IntVar()
motor_4_on = tk.IntVar()
motor_3_on = tk.IntVar()
motor_2_on = tk.IntVar()
motor_1_on = tk.IntVar()

# Display Ports
ports = serial.tools.list_ports.comports()
serialInst = serial.Serial()
portsList = []

for one in ports:
    portsList.append(one.device)
    
selected_port = tk.StringVar(win)
   
# Set the default value of the variable
selected_port.set("Select COM Port")
dropdown = tk.OptionMenu(win, selected_port, *portsList)
dropdown.grid(column= 2, row=0)
connect_btn = tk.Button(win, text="Connect", command=connect_serial)
connect_btn.grid(column=3, row=0, padx=10)

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


while True:
    
    command = input("Select motor:  ")
    serialInst.write(command.encode('utf-8'))
    print("The motor is : ", command)
    
    
    
    if command == 'EXIT':
        exit()
        
