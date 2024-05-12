char *longestCommonPrefix(char **strs, int strsSize) {
    if(!strsSize)
        return "";

    int j;
    
    for(size_t i=1; i<strsSize; i++){
        j=0;
        while(strs[0][j]!='\0' && strs[i][j]!='\0' && strs[i][j]==strs[0][j]){
            j++;
        }
        strs[0][j]='\0';
    }
    return strs[0];
}
