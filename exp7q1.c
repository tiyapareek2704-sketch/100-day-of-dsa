#include <stdio.h>

// Function to calculate digital root
int getFamily(int sap_id) {
int last3 = sap_id % 1000;
int sum = 0;


// Add digits of last 3 digits
while(last3 > 0) {
    sum += last3 % 10;
    last3 /= 10;
}

// Reduce to single digit
while(sum > 9) {
    int temp = 0;
    while(sum > 0) {
        temp += sum % 10;
        sum /= 10;
    }
    sum = temp;
}

return sum;  // final family


}

int main() {
int sap_id, family;


printf("Enter Student SAP-ID: ");
scanf("%d", &sap_id);

family = getFamily(sap_id);

printf("SAP-ID: %d\n", sap_id);
printf("Assigned Family: %d\n", family);

return 0;

}
