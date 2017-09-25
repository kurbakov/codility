bool validate(std::string str){
    int num=0;
    int ch = 0;
    for(int i=0; i<str.length(); i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            ch++;
        }
        else if(str[i] >= 'A' && str[i] <= 'Z'){
            ch++;
        }
        else if(str[i] >= '0' && str[i] <= '9'){
            num++;
        }
        else return false;
    }

    if(ch%2==0 && num%2==1)
        return true;
    else
        return false;
}

bool check(std::string s){
    for(auto ch : s)
        if (ch == ' ')
            return true;
    return false;
}

int solution(std::string& str){
    int idx = 0;
    if(!check(str)){
        if(validate(str)){
            return str.length();
        } else return -1;
    }

    int max = -1;
    for(int i=0; i<str.length(); i++){
        if(str[i] == ' '){
            std::string temp = str.substr(idx, i-idx);
            if(validate(temp)){
                int len = (int) temp.length();
                max = max < len ? len : max;
            }

            idx = i+1;
        }
    }
    std::string temp = str.substr(idx, (int) temp.length()-idx);
    if(validate(temp)){
        int len = (int) temp.length();
        max = max < len ? len : max;
    }

    return max;
}
