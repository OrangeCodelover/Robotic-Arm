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

def send_command():
    if not serialInst.is_open:
        messagebox.showwarning("Warning", "Please connect to a COM port first.")
        return
    if motor_5_on.get():
        angle = rotationAngle_5.get()
        cmd = f"5: {angle}"  # Customize your protocol
        serialInst.write(cmd.encode('utf-8'))
        print(f"Sent command: {cmd}")
        
    if motor_4_on.get():
        angle = rotationAngle_4.get()
        cmd = f"4: {angle}"  # Customize your protocol
        serialInst.write(cmd.encode('utf-8'))
        print(f"Sent command: {cmd}")

    if motor_3_on.get():
        angle = rotationAngle_3.get()
        cmd = f"3: {angle}"  # Customize your protocol
        serialInst.write(cmd.encode('utf-8'))
        print(f"Sent command: {cmd}")
        
        
    if motor_2_on.get():
        angle = rotationAngle_2.get()
        cmd = f"2: {angle}"  # Customize your protocol
        serialInst.write(cmd.encode('utf-8'))
        print(f"Sent command: {cmd}")
        
    if motor_1_on.get():
        angle = rotationAngle_1.get()
        cmd = f"1: {angle}"  # Customize your protocol
        serialInst.write(cmd.encode('utf-8'))
        print(f"Sent command: {cmd}")
    
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
rotationAngle_5 = tk.Scale(win, bd = 3, from_=0, to = 90, orient= tk.HORIZONTAL)
rotationAngle_5.grid(column=3, row=1)
tk.Label(win, text="Speed (0 to 90) ").grid(column = 4, row= 1)
# rotationAngle.pack(anchor=tk.CENTER)

# Motor 4
checkbox_4 = tk.Checkbutton(win, text="Motor 4", variable=motor_4_on)
checkbox_4.grid(column=1, row=2)
rotationAngle_4 = tk.Scale(win, bd = 3, from_=0, to = 160, orient= tk.HORIZONTAL)
rotationAngle_4.grid(column=3, row=2)
tk.Label(win, text="Speed (0 to 160) ").grid(column = 4, row= 2)

# Motor 3
checkbox_3 = tk.Checkbutton(win, text="Motor 3", variable=motor_3_on)
checkbox_3.grid(column=1, row=3)
rotationAngle_3 = tk.Scale(win, bd = 3, from_=10, to = 140, orient= tk.HORIZONTAL)
rotationAngle_3.grid(column=3, row=3)
tk.Label(win, text="Speed (10 to 140) ").grid(column = 4, row= 3)

# Motor 2
checkbox_2 = tk.Checkbutton(win, text="Motor 2", variable=motor_2_on)
checkbox_2.grid(column=1, row=4)
rotationAngle_2 = tk.Scale(win, bd = 3, from_=0, to = 100, orient= tk.HORIZONTAL)
rotationAngle_2.grid(column=3, row=4)
tk.Label(win, text="Speed (30 to 100) ").grid(column = 4, row= 4)

# Motor 1
checkbox_1 = tk.Checkbutton(win, text="Motor 1", variable=motor_1_on)
checkbox_1.grid(column=1, row=5)
rotationAngle_1 = tk.Scale(win, bd = 3, from_=0, to = 160, orient= tk.HORIZONTAL)
rotationAngle_1.grid(column=3, row=5)
tk.Label(win, text="Speed (0 to 160) ").grid(column = 4, row= 5)



send_btn = tk.Button(win, text="RUN", command=send_command)
send_btn.grid(column=3, row=6, pady=10)

win.mainloop()