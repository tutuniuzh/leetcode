bool isSelfCrossing(int* distance, int distanceSize) {

    if(distanceSize < 4)
        return false;

    int upBoundX = 0;
    int upBoundY = 0;
    int lowBoundX = 0;
    int lowBoundY = 0;

    int pUpBoundX = 0;
    int pUpBoundY = 0;
    int pLowBoundX = 0;
    int pLowBoundY = 0;

    bool isOutterLoop = false;

    int x,y;
    x = y = 0;

    //north move
    upBoundY = distance[0];
    y = upBoundY;

    //west move
    lowBoundX = 0 - distance[1];
    x = lowBoundX;

    //south move
    y -= distance[2];
    if(y < 0)
        isOutterLoop = true;
    lowBoundY = y;
    

    //east move
    //left
    x += distance[3];
    if(isOutterLoop){
        if(x <= upBoundX){
            isOutterLoop = false;
            if(x == 0)
                upBoundY = 0;
        }else
            //still outter loop
            pUpBoundX = upBoundX;
    }else{
        if(x >= upBoundX)
            return true;
    }
    upBoundX = x;


    for(int i = 4; i < distanceSize; i++){
        if(i % 4 == 0){
            //north move
            //up
            y += distance[i];
            if(isOutterLoop){
                if(y <= upBoundY){
                     isOutterLoop = false;
                     if(y >= pUpBoundY){
                        lowBoundX = pUpBoundX;
                     }
                }else{
                    //still outter loop
                    pUpBoundY = upBoundY;

                }
            }else{
                if(y >= upBoundY)
                    return true;
            }
            upBoundY = y;
        }else if(i % 4 == 1){
            //west move
            //left
            x -= distance[i];
            if(isOutterLoop){
                if(x >= lowBoundX){
                     isOutterLoop = false;
                     if(x <= pUpBoundX){
                        lowBoundY = pUpBoundY;
                     }
                }else{
                    //still outter loop
                    pLowBoundX = lowBoundX;

                }
            }else{
                if(x <= lowBoundX)
                    return true;
            }
            lowBoundX = x;
        }else if (i % 4 == 2){
            //south move
            //down
            y -= distance[i];
            if(isOutterLoop){
                if(y >= lowBoundY){
                     isOutterLoop = false;
                     if(y <= pUpBoundY){
                        upBoundX = pLowBoundX;
                     }
                }else{
                    //still outter loop
                    pLowBoundY = lowBoundY;

                }
            }else{
                if(y <= lowBoundY)
                    return true;
            }
            lowBoundY = y;
        }else{
            //east move
            //left
            x += distance[i];
            if(isOutterLoop){
                if(x <= upBoundX){
                     isOutterLoop = false;
                     if(x >= pLowBoundX){
                        upBoundY = pLowBoundY;
                     }
                }else{
                    //still outter loop
                    pUpBoundX = upBoundX;

                }
            }else{
                if(x >= upBoundX)
                    return true;
            }
            upBoundX = x;
        }
    }

    return false;
    
}