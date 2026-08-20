#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct ClassInterval {
    double lowerBound;
    double upperBound;
    int frequency = 0;
    int cumulativeFrequency = 0;
    double midpoint = 0.0;
    double classSize = 0.0;
    double frequencyDensity = 0.0;
};

int main() {
    vector<double> marks;
    double inputMark;

    cout << "===================================================================\n";
    cout << "          STUDENT MARKS STATISTICAL PROCESSING ENGINE              \n";
    cout << "===================================================================\n";
    cout << "Instructions:\n";
    cout << "1. Copy your 400 marks from your document.\n";
    cout << "2. Right-click or press Ctrl+V to paste them directly below.\n";
    cout << "3. Once pasted, press [Enter], then [Ctrl+Z] (Windows) or [Ctrl+D] (Mac),\n";
    cout << "   and press [Enter] one last time to process the data.\n";
    cout << "===================================================================\n\n";
    cout << "Paste values here:\n";

    while (cin >> inputMark) {
        marks.push_back(inputMark);
    }

    int N = marks.size();
    if (N == 0) {
        cerr << "\nError: No values were detected or input format was invalid.\n";
        return 1;
    }

    cin.clear();

    cout << "\n\nProcessing complete! Successfully captured " << N << " records.\n\n";

    sort(marks.begin(), marks.end());
    double minMark = marks.front();
    double maxMark = marks.back();
    double range = maxMark - minMark;

    double classSizeWidth = 10.0; 
    vector<ClassInterval> table;

    for (double i = 0; i <= 90; i += classSizeWidth) {
        ClassInterval c;
        c.lowerBound = i;
        c.upperBound = (i == 90) ? 100 : i + 9.99; 
        c.midpoint = (c.lowerBound + c.upperBound) / 2.0;
        c.classSize = classSizeWidth;
        table.push_back(c);
    }

    for (double m : marks) {
        for (auto& c : table) {
            if (m >= c.lowerBound && m <= c.upperBound) {
                c.frequency++;
                break;
            }
        }
    }

    int runningSumCF = 0;
    double sumFX = 0.0;       
    double sumFLogX = 0.0;    
    double sumFDivX = 0.0;    
    
    int maxFreq = 0;
    size_t modalClassIndex = 0;

    for (size_t i = 0; i < table.size(); ++i) {
        runningSumCF += table[i].frequency;
        table[i].cumulativeFrequency = runningSumCF;
        table[i].frequencyDensity = (double)table[i].frequency / table[i].classSize;

        if (table[i].frequency > 0) {
            sumFX += table[i].frequency * table[i].midpoint;
            sumFLogX += table[i].frequency * log10(table[i].midpoint);
            sumFDivX += (double)table[i].frequency / table[i].midpoint;
        }

        if (table[i].frequency > maxFreq) {
            maxFreq = table[i].frequency;
            modalClassIndex = i;
        }
    }

    double arithmeticMean = sumFX / N;
    double geometricMean = pow(10, (sumFLogX / N));
    double harmonicMean = N / sumFDivX;

    double medianTarget = N / 2.0;
    size_t medianClassIndex = 0;
    for (size_t i = 0; i < table.size(); ++i) {
        if (table[i].cumulativeFrequency >= medianTarget) {
            medianClassIndex = i;
            break;
        }
    }

    ClassInterval medClass = table[medianClassIndex];
    double prevCF = (medianClassIndex == 0) ? 0 : table[medianClassIndex - 1].cumulativeFrequency;
    double median = medClass.lowerBound + ((medianTarget - prevCF) / medClass.frequency) * classSizeWidth;

    ClassInterval modClass = table[modalClassIndex];
    double f_modal = modClass.frequency;
    double f_prev = (modalClassIndex == 0) ? 0 : table[modalClassIndex - 1].frequency;
    double f_next = (modalClassIndex == table.size() - 1) ? 0 : table[modalClassIndex + 1].frequency;
    
    double delta1 = f_modal - f_prev;
    double delta2 = f_modal - f_next;
    double mode = modClass.lowerBound + (delta1 / (delta1 + delta2)) * classSizeWidth;

    cout << fixed << setprecision(2);
    cout << "========================================================================================\n";
    cout << "Class Interval\tFreq\tMidpoint\tClassSize\tFreqDensity\tCumFreq\n";
    cout << "========================================================================================\n";
    for (auto& c : table) {
        cout << (int)c.lowerBound << " - " << (int)c.upperBound << "\t\t" 
             << c.frequency << "\t" 
             << c.midpoint << "\t\t" 
             << c.classSize << "\t\t" 
             << c.frequencyDensity << "\t\t" 
             << c.cumulativeFrequency << "\n";
    }
    cout << "========================================================================================\n";

    cout << "\n--- DESCRIPTIVE STATISTICAL METRICS ---\n";
    cout << "Sample Size (N)  : " << N << " students\n";
    cout << "Data Range       : " << range << " (Min: " << minMark << " | Max: " << maxMark << ")\n";
    cout << "Arithmetic Mean  : " << arithmeticMean << "\n";
    cout << "Geometric Mean   : " << geometricMean << "\n";
    cout << "Harmonic Mean    : " << harmonicMean << "\n";
    cout << "Modal Class      : " << (int)table[modalClassIndex].lowerBound << " - " << (int)table[modalClassIndex].upperBound << "\n";
    cout << "Calculated Mode  : " << mode << "\n";
    cout << "Median Class     : " << (int)table[medianClassIndex].lowerBound << " - " << (int)table[medianClassIndex].upperBound << "\n";
    cout << "Calculated Median: " << median << "\n";

    return 0;
}