//hard-coded path navigation (go around the perimeter of the grid, detect block, reverse path to star
void FCpath(void) {
  LFSensorRead(); // calls the sensor reading
  LineFollowStart();  // calls the line sensors

  // first left turn
  if (!LT1) {
    if ((LFSensorReading[0]== 0 )&&(LFSensorReading[1]== 0 )&&(LFSensorReading[2]== 0 )&&(LFSensorReading[3]== 0)) {Forward();} 
      // On the line, go forward
       else if ((LFSensorReading[0]== 1 )&&(LFSensorReading[1]== 1 )&&(LFSensorReading[2]== 1 )&&(LFSensorReading[3]== 1)) {Left();}
      // Left sensor is on the line, turn left
       else if ((LFSensorReading[1]== 0 )&&(LFSensorReading[2]== 1)) {Forward();}
      // Right sensor is on the line, go forward
    
    if (LT1) {
      // Reset the robot's state after the first left turn
      resetRobotState();
    }
  }

  // ignore first right turn
  else if (LT1 && !RT1) {
    if ((LFSensorReading[0]== 0 )&&(LFSensorReading[1]== 0 )&&(LFSensorReading[2]== 0 )&&(LFSensorReading[3]== 0)) {
      // On the line, go forward
      Forward();
    } else if ((LFSensorReading[1]== 1 )&&(LFSensorReading[2]== 0 )) {
      // Left sensor is on the line, go forward
      Forward();
    } else if ((LFSensorReading[1]== 0 )&&(LFSensorReading[2]== 1 )) {
      // Right sensor is on the line, go forward
      Forward();
      RT1 = true;
    }
  }

  // Handle the second right turn
  else if (LT1 && RT1 && !RT2) {
    if ((LFSensorReading[0]== 0 )&&(LFSensorReading[1]== 0 )&&(LFSensorReading[2]== 0 )&&(LFSensorReading[3]== 0)) {
      // On the line, go forward
      Forward();
    } else if ((LFSensorReading[1]== 1 )&&(LFSensorReading[2]== 0 )) {
      // Left sensor is on the line, go forward
      Forward();
    } else if ((LFSensorReading[0]== 1 )&&(LFSensorReading[1]== 1 )&&(LFSensorReading[2]== 1 )&&(LFSensorReading[3]== 1)) {
      // Right sensor is on the line, turn right
      Right();
      RT2 = true;
    }
  }

  // Handle the third right turn
  else if (LT1 && RT1 && RT2 && !RT3) {
    if ((LFSensorReading[0]== 0 )&&(LFSensorReading[1]== 0 )&&(LFSensorReading[2]== 0 )&&(LFSensorReading[3]== 0)) {
      // On the line, go forward
      Forward();
    } else if ((LFSensorReading[1]== 1 )&&(LFSensorReading[2]== 0 )) {
      // Left sensor is on the line, go forward
      Forward();
    } else if ((LFSensorReading[0]== 0 )&&(LFSensorReading[1]== 0 )&&(LFSensorReading[2]== 1 )&&(LFSensorReading[3]== 1)) {
      // Right sensor is on the line, turn right
      Right();
      RT3 = true;
    }
  }

  else if (LT1 && RT1 && RT2 && RT3 && !RT4) {
    if ((LFSensorReading[0]== 0 )&&(LFSensorReading[1]== 0 )&&(LFSensorReading[2]== 0 )&&(LFSensorReading[3]== 0)) {
      // On the line, go forward
      Forward();
    } else if ((LFSensorReading[1]== 1 )&&(LFSensorReading[2]== 0 )) {
      // Left sensor is on the line, go forward
      Forward();
    } else if ((LFSensorReading[1]== 0 )&&(LFSensorReading[2]== 1 )) {
      // Right sensor is on the line, go forward
      Forward();
      RT4 = true;
    }
  }

   else if (LT1 && RT1 && RT2 && RT3 && RT4 && !RT5) {
    if ((LFSensorReading[0]== 0 )&&(LFSensorReading[1]== 0 )&&(LFSensorReading[2]== 0 )&&(LFSensorReading[3]== 0)) {
      // On the line, go forward
      Forward();
    } else if ((LFSensorReading[1]== 1 )&&(LFSensorReading[2]== 0 )) {
      // Left sensor is on the line, go forward
      Forward();
    } else if ((LFSensorReading[1]== 0 )&&(LFSensorReading[2]== 1 )) {
      // Right sensor is on the line, go forward
      Forward();
      RT5 = true;
    }
  }

  //ignore all other cases 
  else {
    if ((LFSensorReading[1]== 0 )&&(LFSensorReading[2]== 0 )) {
      // On the line, go forward
      Forward();
    } else if ((LFSensorReading[0]== 0 )&&(LFSensorReading[1]== 1 )&&(LFSensorReading[2]== 0 )) {
      // Left sensor is on the line, go forward
      Forward();
    } else if ((LFSensorReading[1]== 0 )&&(LFSensorReading[2]== 1 )&&(LFSensorReading[3]== 0 )) {
      // Right sensor is on the line, go forward
      Forward();
    }
  }
}


void resetRobotState() {
  LT1 = true;
  RT1 = false;
  RT2 = false;
  RT3 = false;
  RT4 = false;
  RT5 = false;
  RT6 = false;
  RT7 = false;
  RT8 = false;
  RT9 = false;
  LT2 = false;
  
}