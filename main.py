import uinput, serial, time


def main():
    #Setup uinput
    events = (
        uinput.BTN_TRIGGER_HAPPY1,
        uinput.BTN_TRIGGER_HAPPY2,
        uinput.BTN_TRIGGER_HAPPY3,
        uinput.BTN_TRIGGER_HAPPY4,
        uinput.BTN_TRIGGER_HAPPY5,
        uinput.BTN_TRIGGER_HAPPY6,
        uinput.BTN_TRIGGER_HAPPY7,
        )

    device = uinput.Device(events)

    previous_btn_states=[False,False,False,False,False,False,False]
    current_btn_states=[False,False,False,False,False,False,False]

    ser = serial.Serial('/dev/ttyUSB0', 9800)

    while True:
        #Catch all the buttons pressed before pressing the related keys
        BTN = int(ser.read())
        print(BTN) 
        if BTN:
            BTN = BTN-1
            current_btn_states[BTN] = True
            if current_btn_states != previous_btn_states:
                for idx, val in enumerate(current_btn_states):
                    current_btn_states[idx] = False  
                print(current_btn_states)
                current_btn_states[BTN] = True
                print(current_btn_states)
            else:
                current_btn_states[BTN] = True
        else:
            for idx, val in enumerate(current_btn_states):
                    current_btn_states[idx] = False

        for idx, val in enumerate(current_btn_states):
            if val == True and previous_btn_states[idx] == False:
                device.emit(events[idx], 1) # Press.
                previous_btn_states[idx]=True
            elif val == False and previous_btn_states[idx] == True:
                device.emit(events[idx], 0) # Release.
                previous_btn_states[idx]=False
        


if __name__ == '__main__':
    main()