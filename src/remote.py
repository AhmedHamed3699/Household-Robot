import serial
import pynput

# Serial port configuration (replace with your Arduino's port)
arduino = serial.Serial('COM3', 9600)  # Adjust port and baud rate as needed

# Key mappings (modify these to your desired characters)
key_map = {
    pynput.keyboard.Key.up: 'U',
    pynput.keyboard.Key.down: 'D',
    pynput.keyboard.Key.left: 'L',
    pynput.keyboard.Key.right: 'R',
    pynput.keyboard.Key.ctrl_l: 'G',
    pynput.keyboard.Key.ctrl_r: 'H',
    pynput.keyboard.Key.shift_l: 'Z',
    pynput.keyboard.Key.shift_r: 'X',
    pynput.keyboard.Key.page_up: 'E',
    pynput.keyboard.Key.page_down: 'T',
}

# Function to handle key presses
def on_press(key):
    if key in key_map:
        char = key_map[key]
        arduino.write(char.encode())  # Send character as encoded bytes
    else:
        c = str(key)
        print(c + " " + str(len(c)) + "\n")
        arduino.write(c.encode())  # Send character as encoded bytes
def on_release(key):
    if key in key_map:
        arduino.write('S'.encode())

# Create a listener for key presses
listener = pynput.keyboard.Listener(on_press=on_press, on_release=on_release)
# listener = pynput.keyboard.Listener(on_press=on_press)

listener.start()

# Keep the program running until explicitly stopped (Ctrl+C)
try:
    while True:
        pass
except KeyboardInterrupt:
    listener.stop()
    arduino.close()
    print("Exiting...")
