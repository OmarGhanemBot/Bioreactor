#include <cs50.h>
#include <stdio.h>
#include <string.h>

int Count_Nuc_A(string seq);
int Count_Nuc_T(string seq);
int Count_Nuc_G(string seq);
int Count_Nuc_C(string seq);
int Count_Nuc_U(string seq);
int Check_Type(string seq);
void Comp_SEQ(string seq);

int main(void)
{
    // Promot User To Enter Seq
    string SEQ = get_string("YOUR SEQ IS: ");

    // Promot User To Enter Seq Direction
    string Direction = get_string("Direction of Your seq is : ");
	string leading = "5-3";
	string lagging = "3-5";
	int res1 = strcmp(leading, Direction);
	int res2 = strcmp(lagging, Direction);
    // Give Complimentry Seq
    if (res1 == 0)
    {
        printf("COMPLEMENTARY SEQ: ");
        printf("3'-> ");
        Comp_SEQ(SEQ);
        printf(" <- 5'\n");
    }
    else if (res2 == 0)
    {
        printf("COMPLEMENTARY SEQ: ");
        printf("5'->");
        Comp_SEQ(SEQ);
        printf("<- 3'\n");
    }
	else
	{
        printf("You should enter the direction by entring the number of carbon atom of the *Deoxyribose Sugar* or *Ribose Sugar* as following :\n3-5 ==  OR  ==  5-3  == {without *spaces* should have *-* in between}");
        return 1;
	}


    // Check Type of Nucleic acid

    int check =Check_Type(SEQ);
    if(check == 0)
    {
        printf("Nucleic acid Type is **DNA**\n");
    }
    else if (check >= 1)
    {
        printf("Nucleic acid Type is **RNA**\n");
    }

    // Calculate The Length Of The SEQ
    int DNA_SEQ_LENGTH = strlen(SEQ);
    printf("SEQ length is %d\n", DNA_SEQ_LENGTH);

    // Calculate Number Of Nucleotides
    int N_A = Count_Nuc_A(SEQ);
    printf("Aden_Nuc  =%i\n", N_A);

    int N_G = Count_Nuc_G(SEQ);
    printf("Guan_Nuc  =%i\n", N_G);

    int N_C = Count_Nuc_C(SEQ);
    printf("Cyto_Nuc  =%i\n", N_C);

    int N_T = Count_Nuc_T(SEQ);

    int N_U = Count_Nuc_U(SEQ);

    if (N_U > 0)
    {
        printf("Urac_Nuc  =%i\n", N_U);
    }
    else if (N_T > 0)
    {
        printf("Thym_Nuc  =%i\n", N_T);
    }
}

int Count_Nuc_A(string seq)
{
    int A_number = 0;
    int N = strlen(seq);

    for (int i = 0; i < N; i++)
    {
        if (seq[i] == 'A' || seq[i] == 'a')
        {
            A_number++;
        }
    }
    return A_number;
}

int Count_Nuc_G(string seq)
{
    int G_number = 0;
    int N = strlen(seq);

    for (int i = 0; i < N; i++)
    {
        if (seq[i] == 'G' || seq[i] == 'g')
        {
            G_number++;
        }
    }
    return G_number;
}

int Count_Nuc_C(string seq)
{
    int C_number = 0;
    int N = strlen(seq);

    for (int i = 0; i < N; i++)
    {
        if (seq[i] == 'C' || seq[i] == 'c')
        {
            C_number++;
        }
    }
    return C_number;
}

int Count_Nuc_T(string seq)
{
    int T_number = 0;
    int N = strlen(seq);

    for (int i = 0; i < N; i++)
    {
        if (seq[i] == 'T' || seq[i] == 't')
        {
            T_number++;
        }
    }
    return T_number;
}

int Check_Type(string seq)
{
    int number= 0;
    int len = strlen(seq);
    for (int i = 0; i < len; i++)
    {
        if (seq[i] == 'u' || seq[i] == 'U')
        {
           number++;
        }
    }
    return number;
}

int Count_Nuc_U(string seq)
{
    int u_number = 0;
    int N = strlen(seq);

    for (int i = 0; i < N; i++)
    {
        if (seq[i] == 'U' || seq[i] == 'u')
        {
            u_number++;
        }
    }
    return u_number;
}

void Comp_SEQ(string seq)
{
    int N = strlen(seq);
    for (int i = 0; i < N; i++)
    {
        if (seq[i] == 'U' || seq[i] == 'u')
        {
            printf("A");
        }

        if (seq[i] == 'A' || seq[i] == 'a')
        {
            printf("T");
        }

        if (seq[i] == 'T' || seq[i] == 'T')
        {
            printf("A");
        }

        if (seq[i] == 'G' || seq[i] == 'g')
        {
            printf("C");
        }

        if (seq[i] == 'C' || seq[i] == 'c')
        {
            printf("G");
        }
    }
}
