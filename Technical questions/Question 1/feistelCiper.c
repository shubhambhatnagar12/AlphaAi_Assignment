#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{   
    int i=0,j=0;
    char Key[]="abcd123",checkey[8],roundKeyCheck[7];
    

    char data[9],l[5],r[5],cipherData[9],excng;
    //----------- getting data to be encrypted------------
    printf("Entered the data you want to encrypt (Make sure it is of 8bytes i.e 8 characters only) \n");
    scanf("%[^\n]s",data);

    //----------- dividing data into L and R------------
        for(i,j;data[i]!='\0';i++)
        {
            if(i<4)
            {
                l[i]=data[i];
                if(i==3)
                {
                    l[i+1]='\0';
                }
            }
            else
            {
                r[j]=data[i];
                if(j==3)
                {
                    r[j+1]='\0';
                }
                j++;
            }
     }

    //plain text to cipher text
    //---------------------encryption------------
    printf("\nEnter the required key to encrypt the data: \n");
    scanf("%s",checkey);
    if(!strcmp(Key,checkey))
    {  
        for(i=1;i<=15;i++)
        {   
            j=0;
            while (l[j]!='\0')
            {
                l[j]=l[j]^(r[j]+i);
                excng=r[j];
                r[j]=l[j];
                l[j]=excng;
                j++;
            }

        }

     //-----------getting cipher text from R and L
        for (j=0,i= 0; i < 9,j<5; i++)
        {
            if(i<4)
            {
                cipherData[i]=r[i];
            }
            else
            {
                cipherData[i]=l[j];
                j++;
            }
        
        }
        printf("\n The data you entered has been encrypted into = %s",cipherData);

        
    }
    else
    {
        printf("\n The key you entered is wrong, Encryption cannot be done");
        return 0;
    }

//---------------dividing ciphertext into L and R
        for(i=0,j=0;cipherData[i]!='\0';i++)
        {
            if(i<4)
            {
                l[i]=cipherData[i];
                if(i==3)
                {
                    l[i+1]='\0';
                }
            }
            else
            {
                r[j]=cipherData[i];
                if(j==3)
                {
                    r[j+1]='\0';
                }
                j++;
            }
            
        }

// cipher text to plain text 
    //-----------------------decryption---------------
    printf("\n Please provide the key for decryption \n");
    scanf("%s",checkey);
    if(!strcmp(Key,checkey))
    {  
        for(i=15;i>=1;i--)
        {   
            j=0;
            while (r[j]!='\0')
            {
                l[j]=l[j]^(r[j]+i);
                excng=r[j];
                r[j]=l[j];
                l[j]=excng;
                j++;
            }

        }


     //-------getting cipher text from R and L
        for (j=0,i= 0; i < 9,j<5; i++)
        {
            if(i<4)
            {
                cipherData[i]=r[i];
            }
            else
            {
                cipherData[i]=l[j];
                j++;
            }
        
        }
        printf("\n Your Decrypted data is = %s ",cipherData);

        
    }
    else
    {
        printf("\n The Key entered by you is wrong encryption cannot be done");
    }

    
    return 0;
}