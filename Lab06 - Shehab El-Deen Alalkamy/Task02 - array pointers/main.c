

int main()
{
    int c, index;
    printf("Enter the number of elements: ");
    scanf("%d", &c);

    int *arr = (int *) malloc(c * sizeof(int));

    for(index = 0 ; index < c ; index++)
        scanf("%d", arr + index);

    printf("\n\n");
    for(index = 0 ; index < c ; index++)
        printf("arr[%d]: %d\n", index, arr[index]);

    free(arr);

    return 0;
}
