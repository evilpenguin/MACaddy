/*
 *  MACaddy.cpp
 *  macChooser
 *
 *  Created by Evilpenguin on 2/12/10.
 *  Copyright 2010 Apple Inc. All rights reserved.
 *
 */
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "MACaddy.h"

using namespace std;

void MAChacker() {
	string answer;
	string macConfig;
	cout << "\n Time to turn off AirPort" << endl;
	cout << "\n Please enter your password" << endl;
	system("sudo /System/Library/PrivateFrameworks/Apple80211.framework/Versions/Current/Resources/airport -z");
	cout << "Awesome, now your AirPort has been disabled" << endl;
	cout << "Please pick your MAC address" << endl;
	cout << "Example: 00:11:22:33:44:55" << endl;
	cin >> answer;
	macConfig += "sudo ifconfig en1 ether ";
	macConfig += answer;
	const char *changer = macConfig.c_str();
	system(changer);
	system("clear");
	cout << "\n Your MAC Address has been changed" << endl;
	cout << "\n Your MAC Address is: " << endl;
	system("ifconfig en1 | grep ether");
	exit(0);
	
}

bool macChanger() {
	string answer;
	string choice;
	cout << "\n Welcome to MACaddy";
	cout << "\n Created by NakedProductions.US";
	cout << "\n Creator: EvilPenguin|" << endl;
	cout << "\n Turn off AirPort: (airport)";
	cout << "\n Look at MAC address: (show)" << endl;
	cout << "\n Answer: ";
	std::cin >> choice;
	if (choice == "show") {
		system("ifconfig en1 | grep ether");
		cout << "\n Now change the MAC Address? (yes/no)" << endl;
		cout << "\n Answer: ";
		cin >> answer;
		if (answer == "yes") {
			MAChacker();
		}
		else {
			system("clear");
			cout << "\n Good Bye!: " << endl;
			return 0;
		}
	}
	else if (choice == "airport") {
		MAChacker();
	}
	
	return 0;
}
	
