#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const string succ_mes = "The vocabulary you just added has been just Added!\n";
const string fail_mes = "Sorry, something went wrong!\nYou have better to fix it soon!\n";
class Vocabulary
{
private:
    string vo;
    string mean;
public:
    void set_vo(const string v);
    void set_mean(const string m);
    const string get_vo();
    const string get_mean();
    void apart(const string sentence,Vocabulary *vocabulary);
};
void Vocabulary::set_vo(const string v)
{
    vo = v;
}
void Vocabulary::set_mean(const string m)
{
    mean = m;
}
const string Vocabulary::get_vo()
{
    return vo;
}
const string Vocabulary::get_mean()
{
    return mean;
}
void Vocabulary::apart(const string sentence,Vocabulary *vocabulary)
{
    string v_temp;
    string m_temp;
    int space=0;
    for(int i=0; i<sentence.length(); i+=1)
    {
        if(sentence[i]!=' ')
        {
            v_temp+=sentence[i];
        }
        else
        {
            space = i;
            break;
        }
    }
    for(int i=space+1; i<sentence.length(); i+=1)
    {
        m_temp+=sentence[i];
    }
    vocabulary->vo = v_temp;
    vocabulary->mean = m_temp;
    //cout << vocabulary->vo << "**********" << vocabulary->mean << endl;
}
bool voc_cmp(Vocabulary &a,Vocabulary &b)
{
    return a.get_vo()<b.get_vo();
}
const string add_volcabulary(string vo, string mean)
{
    fstream file;
    file.open("vocabulary test.txt",ios::app);
    if(file.fail())
    {
        return fail_mes;
    }
    else
    {
        file << vo << " ";
        file << mean << endl;
        return succ_mes;
    }
}
void voc_sort_and_write(ifstream *fin)
{
    fin->open("vocabulary test.txt",ios::in);
    vector <Vocabulary> voc_vec;
    string temp_voc;
    Vocabulary tmp_vol;
    while(getline(*fin, temp_voc))
    {
        //cout << temp_voc<<endl;
        tmp_vol.apart(temp_voc,&tmp_vol);
        voc_vec.push_back(tmp_vol);
    }
    fin->close();
    sort(voc_vec.begin(), voc_vec.end(),voc_cmp);
    fstream file;
    file.open("vocabulary test.txt",ios::out);
    if(file.fail())
    {
        cout << fail_mes;
    }
    for(int i=0; i<voc_vec.size(); i+=1)
    {
        //cout << voc_vec[i].get_vo() << " " << voc_vec[i].get_mean() << endl;
        file << voc_vec[i].get_vo() << " " << voc_vec[i].get_mean() << endl;
    }
}
int main()
{
    ifstream fin;
    int line=0;
    string tmps;
    fin.open("vocabulary test.txt",ios::in);
    while(getline(fin,tmps))
    {
        line+=1;
    }
    fin.close();
    int fun_num=0;
    bool break_flag=false;
    while(!break_flag)
    {
        cout << "Please choose the function you want to do...>\n";
        cout << "(1)Vocabulary test\n";
        cout << "(2)Add new vocabulary\n";
        cout << "(3)Modify the mean of the word\n";
        cout << "(4)Delete a word\n";
        cout << "(5)Exit\n";
        scanf("%d",&fun_num);
        switch(fun_num)
        {
        case 1:
        {
            system("cls");
            printf("Please input 1 to start...>");
            int start_num=0;
            scanf("%d",&start_num);
            if(start_num==1)
            {
                while(start_num == 1)
                {
                    srand(time(NULL));
                    int a = rand()%line+1;
                    //printf("The Random Number is %d.\n",a);
                    ifstream fpin;
                    fpin.open("vocabulary test.txt",ios::in);
                    if(fpin==0)
                    {
                        printf("Cannot open vocabulary test.txt.");
                        return 0;
                    }
                    int num=0;
                    string vo = "string";
                    string get;
                    while(num!=a)
                    {
                        getline(fpin, vo);
                        get = vo;
                        get = get+"\n";
                        num+=1;
                    }
                    int charnum=0, spacenum=0;
                    cout << endl;
                    while(get[charnum]>='a' && get[charnum]<='z')
                    {
                        cout << get[charnum];
                        charnum+=1;
                    }
                    cout << '\n';
                    cout << endl;
                    system("pause>nul");
                    cout <<"**************" <<endl;
                    charnum+=1;
                    while(get[charnum]!='\n')
                    {
                        cout << get[charnum];
                        charnum+=1;
                    }
                    cout << endl << "**************" <<  endl << endl;
                    fpin.close();
                    cout << "(1)Next\n(2)Exit(Back to the menu)\n";
                    cin>>start_num;
                    system("cls");
                }
            }
            break;
        }
        case 2:
        {
            system("cls");
            int adding = 1;
            while(adding==1)
            {
                printf("Please input the vocabulary you want to add in the database...>\n");
                Vocabulary vocabulary;
                string temp = "\n";
                string v,m;
                getline(cin,temp);
                getline(cin, v);
                vocabulary.set_vo(v);
                cout << vocabulary.get_vo() << endl;
                printf("And its mean...>\n");
                getline(cin, m);
                vocabulary.set_mean(m);
                cout << vocabulary.get_mean() << endl;
                cout << add_volcabulary(v,m);
                voc_sort_and_write(&fin);
                system("cls");
                cout << "Do you want to add another vocabulary?\n(1)Yes\n(2)No (Go back to the menu)\n";
                cin>> adding;
                system("cls");
            }
            break;
        }
        case 3:
        {
            system("cls");
            cout << "Please input the word you want to modify its mean...>\n";
            break;
        }
        case 4:
        {
            system("cls");
            cout << "Please input the word you want to delete...>\n";
            break;
        }
        case 5:
        {
            break_flag=1;
            break;
        }
        }
        system("cls");
    }
    return 0;
}
//中文顯示要正常可以從notepad++把編碼方式改成ANSI

