#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>

/*
- Time Complexity: O(N * M * log N), where N is the number of logs and M is the maximum length of a single log.
  This is because sorting the letter-logs is the most time-consuming part.
- Space Complexity: O(N * M), where N is the number of logs and M is the maximum length of a single log.
  This is because we create new lists to store the letter and digit logs.
*/
vector<string> reorderLogFiles(vector<string>& logs) {
    // Step 1: Create an empty list called letterLogs because we need a place to store all the logs that have letters after their ID.
    vector<string> letterLogs;
    // Step 2: Create an empty list called digitLogs because we need a place to store all the logs that have numbers after their ID.
    vector<string> digitLogs;

    // Step 3: Go through each log one by one from the original list because we need to check every single log to decide if it's a letter-log or a digit-log.
    for (int i = 0; i < logs.size(); i++) {
        // Step 4: Get the current log and put it in a variable called 'log' because it's easier to work with a single log at a time.
        string log = logs[i];
        // Step 5: Find the position of the first space in the log because this separates the log's ID from its content.
        int pos = log.find(' ');

        // Step 6: Check the character right after the first space to see if it's a number because this is how we tell if it's a digit-log or a letter-log.
        if (isdigit(log[pos + 1])) {
            // Step 7: If it is a digit-log, add it to the 'digitLogs' list because we need to keep all digit-logs together in their original order.
            digitLogs.push_back(log);
        } else {
            // Step 8: If it is a letter-log, add it to the 'letterLogs' list because letter-logs need to be sorted separately.
            letterLogs.push_back(log);
        }
    }

    // Step 9: Sort the 'letterLogs' list using a custom rule because the problem requires a special order: first by content, then by ID.
    sort(letterLogs.begin(), letterLogs.end(), [](string a, string b) {
        // Step 10: Inside the sorting rule, find the first space in log 'a' because we need to split it into its ID and content parts.
        int posA = a.find(' ');
        // Step 11: Find the first space in log 'b' because we also need to split this log to compare it with log 'a'.
        int posB = b.find(' ');
        
        // Step 12: Get the ID part of log 'a' (everything before the space) because we might need it for sorting if the contents are the same.
        string idnA = a.substr(0, posA);
        // Step 13: Get the ID part of log 'b' because we need it for comparison.
        string idnB = b.substr(0, posB);
        
        // Step 14: Get the content part of log 'a' (everything after the space) because this is the primary thing we need to sort by.
        string contentA = a.substr(posA + 1);
        // Step 15: Get the content part of log 'b' because we need it to compare with the content of log 'a'.
        string contentB = b.substr(posB + 1);

        // Step 16: Check if the content of both logs is exactly the same because if they are, we have a tie and must use a different rule.
        if (contentA == contentB) {
            // Step 17: If the contents are the same, sort by the ID in alphabetical order because this is the tie-breaking rule.
            return idnA < idnB;
        } else {
            // Step 18: If the contents are different, sort by the content in alphabetical order because this is the main sorting rule.
            return contentA < contentB;
        }
    });

    // Step 19: Go through each log in the 'digitLogs' list because now we need to add them to the end of the sorted 'letterLogs'.
    for (int i = 0; i < digitLogs.size(); i++) {
        // Step 20: Add each digit-log to the end of the 'letterLogs' list because the final result must have all letter-logs first, 
        // followed by all digit-logs in their original order.
        letterLogs.push_back(digitLogs[i]);
    }

    // Step 21: Return the modified 'letterLogs' list because it now contains all the logs sorted and combined in the correct order.
    return letterLogs;
}

int main() {
    vector<string> logs = {
        "dig1 8 1 5 1",
        "let1 art can",
        "dig2 3 6",
        "let2 own kit dig",
        "let3 art zero"
    };

    vector<string> result = reorderLogFiles(logs);

    cout << "Reordered Logs:" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}