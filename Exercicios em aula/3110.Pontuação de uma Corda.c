int scoreOfString(char* s) {
    
    int len = strlen(s);
     int result = 0;

    for(int i = 0; i < len - 1 ; i++){

        int dif = abs(s[i]-s[i+1]);

        result += dif;
    }   

    return result;
}