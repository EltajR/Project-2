#include <stdio.h>
#include <string.h>
// Problem description: https://cs50.harvard.edu/x/2022/psets/1/credit/


// Credit card number validator -->
int main(){
    //declare functions -->
    int check_length (char [], int );
    int initial_validator(char []);
    int second_validator(char []);
    int determine_card_type(char []);
    void print_card_type(int );
    void print_invalid();

    while (1){
    //execution -->
    //get the user input -->
    char var_by_user [256];
    scanf("%s", &var_by_user);

    //determine the card type (preliminary) for length
    //ct stands for the card type
    int ct = determine_card_type(var_by_user);

    //check length based on the length based on the card type
    int first_boolean = check_length(var_by_user, ct);

    //if the length is valid, continue, checking other conditions
    if (first_boolean){
        int second_boolean = initial_validator(var_by_user);
        if (second_boolean){
            int third_boolean = second_validator(var_by_user);
            if (third_boolean) {
                print_card_type(ct);
            }
            else print_invalid();
        } else print_invalid();
    } else print_invalid();}}

// Does the entered string contain only numbers between 0-9?
// Returns 1 if this condition is met, otherwise 0;
int initial_validator(char user_input []){
   int true_or_false = 1;
   int string_length = strlen(user_input);
    //checking individual characters -->
    for (int i = 0; i < string_length; i++) {
        char curr = user_input [i];
        if(!(curr >= '0' && curr <= '9'))
        {
            true_or_false = 0;
            break;
        }}
    return true_or_false;
}

//check length based on the type of the card
int check_length(char user_input[], int ct){
    int string_length = strlen(user_input);
    if(ct == 0 && string_length == 15) return 1;
    else if(ct == 1 && string_length == 16) return 1;
    else if((ct == 2) && (string_length == 13 || string_length == 16)) return 1;
    else return 0;}

    // main logic -->
int second_validator(char user_input []){
    //function declaration
    int charToInt(char );
    int endsWith_0(int );

   int len = strlen(user_input);
   int sum_of_not_multiplied = 0;
   int sum_of_multiplied = 0;
   int total_sum;
   //check every second character -->
   int keepTrack = 0;
    for (int i = len - 1 ; i >= 0; i--) {
        int curr = charToInt(user_input[i]);
        //take every second number
        if (keepTrack) {
            int mul_int = curr * 2;
            if (mul_int > 9) sum_of_multiplied += mul_int - 9;
            else sum_of_multiplied += mul_int;
            keepTrack = 0;}
         else {
             sum_of_not_multiplied += curr;
             keepTrack = 1;
         }
    }
    total_sum = sum_of_multiplied + sum_of_not_multiplied;
    return endsWith_0(total_sum);
}

int endsWith_0(int sum) {
    if (sum % 2 == 0 && sum % 5 == 0) return 1;
    else return 0;
}

// 0 stands for AMEX; 1 stands for MASTERCARD; 2 stands for VISA
int determine_card_type(char user_input []){
    char first_num = user_input[0];
    char second_num = user_input[1];
    //if it starts with 4, it is a VISA
    if (first_num == '4') return 2;
    //if it starts with 34 or 37, it is an AMEX
    else if ((first_num == '3') && (second_num == '4' || second_num == '7')) return 0;
    //in other cases it is a MASTERCARD
    else return 1;
}

void print_card_type(int ct){
    // ct stands for card type
    // Constant variables -->
    const char ct_0_ [] = "AMEX";
    const char ct_1_[] = "MASTERCARD";
    const char ct_2_ [] = "VISA";

    // print according to the type -->
    if (ct == 0) printf("%s\n",ct_0_);
    else if (ct == 1) printf("%s\n", ct_1_);
    else printf("%s\n", ct_2_);}

void print_invalid(){ printf("%s\n", "INVALID"); }

int charToInt(char c) { return (int) c - (int) '0'; }