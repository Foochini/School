#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getData(char** uName, char* team[3]) {
  char fName[30];
  char lName[30];
  int luckyNum;

  printf("Please enter your first and last name: ");
  scanf("%s %s", fName, lName);

  printf("%s %c., enter your lucky number (<100): ", fName, lName[0]);
  scanf("%d", &luckyNum);

  *uName = (char*)malloc(61 * sizeof(char));
  sprintf(*uName, "%c%s%d", fName[0], lName, luckyNum);

  for (int i = 0; i < 3; i++) {
    team[i] = (char*)malloc(30 * sizeof(char));
    printf("Please enter team member %d: ", i + 1);
    scanf("%s", team[i]);
  }

  return luckyNum;
}

int main() {
  char* username;
  char* teamNames[3];
  int   luckyNum;
  luckyNum = getData(&username, teamNames);
  printf("The username is %s\n", username);
  printf("%s's lucky number is %d.\n", username, luckyNum);
  printf("The team members are:\n  - %s\n  - %s\n  - %s\n",
                     teamNames[0],teamNames[1],teamNames[2]);
  return 0;
}
