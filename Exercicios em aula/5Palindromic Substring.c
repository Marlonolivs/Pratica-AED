char* longestPalindrome(char* s) {

    int len = strlen(s);

    if(len < 2) return s;

    int start = 0;
    int maxlen = 1;

    for(int i = 0; i < len ; i++){
        for(int j = 0; j <= 1; j++ ){
            int left = i;
            int right = i+j;

            while(left >= 0 && right < len && s[left]==s[right]){
                int tamAtual = right - left +1;

                if(tamAtual > maxlen){
                    start = left;
                    maxlen = tamAtual;
                }

                 left --;
                right ++;
            }
        }
    }

    char* result = (char*)malloc((maxlen + 1)* sizeof(char));
    strncpy(result, s + start, maxlen);
    result[maxlen] = '\0';

    return result;

}