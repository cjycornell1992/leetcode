int romanToIntHelper(char c);

bool romanCompare(char c,char c_next);

int romanToInt(char* s) {
    bool add = false;
    int sum = 0;
    char c,c_next;
    int length = 0;
    int i;
    while(s[length]!=0){
        length++;
    }
    for(i = 0; i < length; i++){
        c = s[i];
        c_next = s[i + 1];
        add = romanCompare(c,c_next);
        if(add) sum += romanToIntHelper(c);
        else sum -= romanToIntHelper(c);
    }
    // sum += romanToIntHelper(s[length - 1]);
    return sum;
}

//I(1)，V(5)，X(10)，L(50)，C(100)，D(500)，M(1000)    
int romanToIntHelper(char c){
    switch (c){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default : return 0;
    }
}

bool romanCompare(char c,char c_next){
     int cPriority = romanToIntHelper(c);
     int cNextPriority = romanToIntHelper(c_next);
     if(cPriority == 1 || cPriority == 10 || cPriority == 100){
         if(cNextPriority > cPriority) return false;
         else return true;
     } else return true;
}    
