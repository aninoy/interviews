#include <iostream>
#include <stdio.h>
#include <map>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	map<string, int> wordCount;

	wordCount.insert(make_pair("the", 50));
	wordCount.insert(make_pair("how", 56));
	wordCount.insert(make_pair("what", 23));
	wordCount.insert(make_pair("who", 65));
	wordCount.insert(make_pair("where", 5));

	map<string, int>::iterator it;

	wordCount["the"] = 100;

	for(it = wordCount.begin(); it != wordCount.end(); it++) {
		cout<<it->first<<" => "<<it->second<<"\n";
	}

	for(auto& y : wordCount) {
		cout<<y.first<<" => "<<y.second<<endl;
		// cout<<y<<endl;
	}

	if(wordCount.find("who") != wordCount.end()){
		cout<<"Found key, value: "<<wordCount.find("who")->second<<"\n";
	}
	else {
		cout<<"Not found!\n";
	}

	return 0;
}
