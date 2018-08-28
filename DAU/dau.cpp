#include"../Function.h"
int main(int argc,char **argv)
{
    if(argc!=2)
	{
		cout<<"error!,Please input the necessary filename" <<endl;
		return 0;
	}
	log("Users Account");
	string filenamein = argv[1];
	//string filenameout = "Out.txt";
	ifstream ifsrule(filenamein);
	if (ifsrule)
		UsersAccount(ifsrule);
	ifsrule.close();
    return 0;
}