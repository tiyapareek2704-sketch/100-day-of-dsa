#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;

    while(1)
    {
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Push selected\n");
                break;

            case 2:
                printf("Pop selected\n");
                break;

            case 3:
                printf("Display selected\n");
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}