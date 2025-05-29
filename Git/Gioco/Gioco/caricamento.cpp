#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void showLoadingBar(int totalSteps, int delayMillis) {
    const int barWidth = 50;

    for (int i = 0; i <= totalSteps; ++i) {
        int percent = (i * 100) / totalSteps;
        int progress = (i * barWidth) / totalSteps;

        cout <<"\r[";
        for (int j = 0; j < barWidth; ++j) {
        	char a=219;
            if (j < progress) cout <<a;
            else cout << "-";
        }
        cout << "] " << percent << "%";
        cout.flush();

        this_thread::sleep_for(chrono::milliseconds(delayMillis));
    }

    cout << "\nCaricamento completato!" << endl;
}

int main() {
	cout<<"Caricamento"<<endl;
    showLoadingBar(100, 20); // 100 passi, 50 ms di attesa tra ognuno
    return 0;
}
