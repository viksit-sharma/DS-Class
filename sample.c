#include <stdio.h>
#include <limits.h>
void main()
{
    // KADANE ALGORITHM
    int arr[] = {1, -2, 6, -1, 3};
    int maxS = INT_MIN;
    int currSum = arr[0];
    for (int i = 0; i < 5; i++)
    {
        currSum += arr[i];
        if (maxS < currSum)
        {
            maxS = currSum;
        }
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    printf("%d", maxS);
}
// void main()
// {
// PREFIX SUM METHOD
//     int arr[] = {1, -2, 6, -1, 3};
//     int maxS = INT_MIN;
//     int prefix[5] = {0};
//     prefix[0] = arr[0];
//     for (int i = 1; i < 5; i++)
//     {
//         prefix[i] = prefix[i - 1] + arr[i];
//     }
//     for (int i = 0; i < 5; i++)
//     {
//         for (int j = i; j < 5; j++)
//         {
//             int currSum = 0;
//             currSum = (i == 0) ? prefix[j] : prefix[j] - prefix[i - 1];
//             if (maxS < currSum)
//             {
//                 maxS = currSum;
//             }
//         }
//     }
//     printf("%d", maxS);
// }
// void main()
// {
// BRUTE FORCE METHOD
//     int arr[] = {1, -2, 6, -1, 3};
//     int maxS = INT_MIN;
//     for (int i = 0; i < 5; i++)
//     {
//         for (int j = 0; j < 6; j++)
//         {
//             int sum = 0;
//             for (int k = i; k < j; k++)
//             {
//                 sum += arr[k];
//             }
//             printf("%d \n", sum);
//             if (sum > maxS)
//             {
//                 maxS = sum;
//             }
//         }
//     }
//     printf("\n%d", maxS);
// }