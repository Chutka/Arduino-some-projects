
int pin[16] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};        
int row[16] = {pin[12], pin[2], pin[7], pin[1], pin[11], pin[6], pin[10], pin[4]};
int col[16] = {pin[3], pin[9], pin[8], pin[13], pin[5], pin[0], pin[15], pin[14]};

int v=3; 
int dms=400; 


boolean P[8][8] = 
{0,1,1,1,1,1,1,0,
0,1,1,1,1,1,1,0,  
0,1,1,0,0,1,1,0,  
0,1,1,0,0,1,1,0,  
0,1,1,0,0,1,1,0,  
0,1,1,0,0,1,1,0,  
0,1,1,0,0,1,1,0,  
0,1,1,0,0,1,1,0}; 

boolean R[8][8] = 
{
0,1,1,1,1,1,1,0,
0,1,1,1,1,1,1,0,  
0,1,1,0,0,1,1,0,  
0,1,1,0,0,1,1,0,  
0,1,1,1,1,1,1,0,  
0,1,1,1,1,1,1,0,  
0,1,1,0,0,0,0,0,  
0,1,1,0,0,0,0,0}; 

boolean I[8][8] = 
{0,1,1,0,0,1,1,0,
0,1,1,0,0,1,1,0,  
0,1,1,0,0,1,1,0,  
0,1,1,0,1,1,1,0,  
0,1,1,1,1,1,1,0,  
0,1,1,1,0,1,1,0,  
0,1,1,0,0,1,1,0,  
0,1,1,0,0,1,1,0};

boolean V[8][8] = 
{0,1,1,1,1,1,0,0,
0,1,1,1,1,1,1,0,  
0,1,1,0,0,1,1,0,  
0,1,1,1,1,1,0,0,  
0,1,1,0,0,1,1,0,  
0,1,1,0,0,1,1,0,  
0,1,1,1,1,1,1,0,  
0,1,1,1,1,1,1,0};

boolean E[8][8] = 
{0,1,1,1,1,1,1,0,
0,1,1,1,1,1,1,0,  
0,1,1,0,0,0,0,0,  
0,1,1,1,1,1,0,0,  
0,1,1,1,1,1,0,0,  
0,1,1,0,0,0,0,0,  
0,1,1,1,1,1,1,0,  
0,1,1,1,1,1,1,0};

boolean T[8][8] = 
{0,1,1,1,1,1,1,0,
0,1,1,1,1,1,1,0,  
0,0,0,1,1,0,0,0,  
0,0,0,1,1,0,0,0,  
0,0,0,1,1,0,0,0,  
0,0,0,1,1,0,0,0,  
0,0,0,1,1,0,0,0,  
0,0,0,1,1,0,0,0};

boolean result[8][8];

void setup(){
  for (int i = 0; i < 16; i++) {
    pinMode(pin[i], OUTPUT);
  }
  for (int i=0; i<8; i++)
    {
      digitalWrite(row[i],HIGH); 
    }
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        result[i][j] = P[i][j];
      }
    }  
}
int counter = 0;
void loop()
{
  for (int i = 0; i < 8; i++) {
    switch(counter) {
      case 0:
        paint(result, v);
        scroll(result, R); 
      break;
      case 1:
        paint(result, v);
        scroll(result, I); 
      break;
      case 2:
        paint(result, v);
        scroll(result, V); 
      break;
      case 3:
        paint(result, v);
        scroll(result, E); 
      break;
      case 4:
        paint(result, v);
        scroll(result, T); 
      break;
      case 5:
        paint(result, v);
        scroll(result, P); 
      break;
    }
  }
  counter = (counter + 1) % 6;
}

void paint(boolean screen[8][8], int v) 
{  
int i, j;
for (int c=0; c <v; c ++) 
  {
    for (i=0; i<8; i++)
      for (j=0; j<8; j++)
        {
          if (screen[i][j]==1)            
           {
              digitalWrite(row[i], LOW); 
              digitalWrite(col[j], HIGH); 
              delayMicroseconds(dms); 
              digitalWrite(row[i], HIGH); 
              digitalWrite(col[j], LOW); 
           }
            else 
             {
                 digitalWrite(row[i], HIGH); 
                 digitalWrite(col[j], LOW); 
                 delayMicroseconds(dms); 
                 digitalWrite(row[i], HIGH); 
                 digitalWrite(col[j], LOW);
            } 
        } 
    }
}

void scroll(boolean screen[8][8], boolean matrix[8][8]) 
{
boolean buf[8][1]; 
  for (int i=0; i<8; i++)
  {
    buf[i][0]=matrix[i][0]; 
  }
  for (int i=0; i<8; i++)
    for (int j=0; j<8; j++)
      {
        matrix[i][j]=matrix[i][j + 1];
        screen[i][j]=screen[i][j+1]; 
      }
  for (int i=0; i<8; i++)
  {
    matrix[i][8 - 1]=buf[i][0];
    screen[i][8-1]=buf[i][0]; 
  }
}
