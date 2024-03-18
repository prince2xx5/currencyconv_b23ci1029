#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100 

float convertCurrency(float amount, float rate) {
    return amount * rate;
}

float rate(float currency1, float currency2){
    float val =(currency2/currency1);
    return val;
}

int main() {
    printf("Hey There!!!! Wanna convert Curreny?\n");
    printf("No Worries,Just follow the steps\n");
    float amount;
    char country_input1[MAX_LENGTH];
    char currency_input1[MAX_LENGTH];
    int country_given1 = 0, currency_given1 = 0;

    printf("Enter the country (or press Enter to skip): ");
    fgets(country_input1, sizeof(country_input1), stdin);
    country_input1[strcspn(country_input1, "\n")] = '\0';
    if (country_input1[0] != '\0') {
        country_given1 = 1;
        
        for (int i = 0; country_input1[i] != '\0'; ++i) {
            country_input1[i] = toupper(country_input1[i]);
        }
    }

    printf("Enter the currency You have (or press Enter to skip): ");
    fgets(currency_input1, sizeof(currency_input1), stdin);
    currency_input1[strcspn(currency_input1, "\n")] = '\0';
    if (currency_input1[0] != '\0') {
        currency_given1 = 1;
        for (int i = 0; currency_input1[i] != '\0'; ++i) {
            currency_input1[i] = toupper(currency_input1[i]);
        }
    }

    FILE *file = fopen("file.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line1[MAX_LENGTH];
    char *country1, *currency1, *rate_str1;
    int match_found1 = 0;
    float rate1 = 0;

    while (fgets(line1, sizeof(line1), file)) {
        country1 = strtok(line1, " ");
        currency1 = strtok(NULL, " ");
        rate_str1 = strtok(NULL, " ");

        if (country1 != NULL && currency1 != NULL && rate_str1 != NULL) {
            if ((!country_given1 || strcmp(country1, country_input1) == 0) &&
                (!currency_given1 || strcmp(currency1, currency_input1) == 0)) {
                rate1 = atof(rate_str1);
                match_found1 = 1;
            }
        }
    }

    if (!match_found1) {
        printf("No matching exchange rate found.\n");
        printf("Sorry for inconvenience. Try Again!!!\n");
        return 1;
    }

    fclose(file);

    printf("Enter amount: ");
    scanf("%f", &amount);
    getchar();

    char country_input2[MAX_LENGTH];
    char currency_input2[MAX_LENGTH];
    int country_given2 = 0, currency_given2 = 0;

    printf("Enter the country (or press Enter to skip): ");
    fgets(country_input2, sizeof(country_input2), stdin);
    country_input2[strcspn(country_input2, "\n")] = '\0';
    if (country_input2[0] != '\0') {
        country_given2 = 1;
        
        for (int i = 0; country_input2[i] != '\0'; ++i) {
            country_input2[i] = toupper(country_input2[i]);
        }
    }

    printf("Enter the currency You Want to convert into (or press Enter to skip): ");
    fgets(currency_input2, sizeof(currency_input2), stdin);
    currency_input2[strcspn(currency_input2, "\n")] = '\0';
    if (currency_input2[0] != '\0') {
        currency_given2 = 1;
        for (int i = 0; currency_input2[i] != '\0'; ++i) {
            currency_input2[i] = toupper(currency_input2[i]);
        }
    }

    file = fopen("file.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line2[MAX_LENGTH];
    char *country2, *currency2, *rate_str2;
    int match_found2 = 0;
    float rate2 = 0;

    while (fgets(line2, sizeof(line2), file)) {
        country2 = strtok(line2, " ");
        currency2 = strtok(NULL, " ");
        rate_str2 = strtok(NULL, " ");

        if (country2 != NULL && currency2 != NULL && rate_str2 != NULL) {
            if ((!country_given2 || strcmp(country2, country_input2) == 0) &&
                (!currency_given2 || strcmp(currency2, currency_input2) == 0)) {
                rate2 = atof(rate_str2);
                match_found2 = 1;
            }
        }
    }

    if (!match_found2) {
        printf("No matching exchange rate found.\n");
        printf("Sorry for inconvenience. Try Again!!!\n");
        return 1;
    }

    fclose(file);

    float rate_curr = rate(rate1, rate2);
    float final_conversion = convertCurrency(amount, rate_curr);
    printf("Converted amount: %.2f\n", final_conversion);

printf("Thanks For Using:)\n");

    return 0;
}
