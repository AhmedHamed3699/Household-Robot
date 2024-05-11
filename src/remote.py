import serial
import pynput

# Serial port configuration (replace with your Arduino's port)
arduino = serial.Serial('/dev/ttyACM1', 9600)  # Adjust port and baud rate as needed

# Key mappings (modify these to your desired characters)
key_map = {
    pynput.keyboard.Key.up: 'U',
    pynput.keyboard.Key.down: 'D',
    pynput.keyboard.Key.left: 'L',
    pynput.keyboard.Key.right: 'R',
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
