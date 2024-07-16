#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    //todo fix nested if statements 
    //todo fix if statements not working in qc file
    //todo fix errors on closing brackets in qc file
    //todo add support for file names
    //todo name files after inputed file
    //todo add vscode support
    //fix std lib errors?
    //todo add support for multiple files
+
//todo bundle with g++ compiler
    ifstream myfile("code.qc");
    ofstream outfile("output.cpp");
    bool debug = false;

    if (!outfile.is_open()) {
        cerr << "Failed to open the file for writing!" << endl;
        return 1;
    }

    if (myfile.is_open()) {
        outfile << "#include <iostream>\nusing namespace std;\n\n\n#include <locale>\nstring to_lower(string s) {\n    for(char& c : s)\n        c = tolower(c);\n    return s;\n}\nint main(int argc, char* argv[]) {\n    string intbuffer;\n    ";

        string line;
        while (getline(myfile, line)) {
            cout << line << '\n';

            size_t pos;
            if ((pos = line.find("print")) != string::npos) {
                line.erase(pos, 5);

                size_t start_pos = line.find('"');
                size_t end_pos = line.find('"', start_pos + 1);

                if (start_pos != string::npos && end_pos != string::npos) {
                    string to_output = line.substr(start_pos + 1, end_pos - start_pos - 1);
                    line.erase(start_pos, end_pos - start_pos + 1);

                    outfile << "    cout << \"" << to_output << "\";";
                }
                else {
                    start_pos = line.find('+');
                    end_pos = line.find('+', start_pos + 1);

                    if (start_pos != string::npos && end_pos != string::npos) {
                        string to_output = line.substr(start_pos + 1, end_pos - start_pos - 1);
                        line.erase(start_pos, end_pos - start_pos + 1);

                        outfile << "    cout << " << to_output << ";";
                    }
                }
            }

            else if ((pos = line.find("intdef")) != string::npos) {
                line.erase(pos, 6);

                size_t start_pos = line.find(' ');
                size_t end_pos = line.find('=', start_pos + 1);

                if (start_pos != string::npos && end_pos != string::npos) {
                    string var_name = line.substr(start_pos + 1, end_pos - start_pos - 1);
                    string to_output = line.substr(end_pos + 1);

                    outfile << "    int " << var_name << " = " << to_output << ";\n";
                }
                else {
                    cerr << "ERROR CODE 1: Invalid declaration of int variable." << endl;
                    return 1;
                }
            }
            else if ((pos = line.find("strdef")) != string::npos) {
                line.erase(pos, 6);

                size_t start_pos = line.find(' ');
                size_t end_pos = line.find('=', start_pos + 1);

                if (start_pos != string::npos && end_pos != string::npos) {
                    string var_name = line.substr(start_pos + 1, end_pos - start_pos - 1);
                    string to_output = line.substr(end_pos + 1);

                    outfile << "    string " << var_name << " = " << to_output << ";\n";
                }
                else {
                    cerr << "ERROR CODE 1: Invalid declaration of string variable." << endl;
                    return 1;
                }
            }
            else if ((pos = line.find("int")) != string::npos) {
                line.erase(pos, 3);

                size_t start_pos = line.find(' ');
                size_t end_pos = line.find('=', start_pos + 1);

                if (start_pos != string::npos && end_pos != string::npos) {
                    string var_name = line.substr(start_pos + 1, end_pos - start_pos - 1);
                    string to_output = line.substr(end_pos + 1);

                    outfile << "     " << var_name << " = " << to_output << ";\n";
                }
                else {
                    cerr << "ERROR CODE 1: Invalid declaration of int variable." << endl;
                    return 1;
                }
            }
            else if ((pos = line.find("str")) != string::npos) {
                line.erase(pos, 3);

                size_t start_pos = line.find(' ');
                size_t end_pos = line.find('=', start_pos + 1);

                if (start_pos != string::npos && end_pos != string::npos) {
                    string var_name = line.substr(start_pos + 1, end_pos - start_pos - 1);
                    string to_output = line.substr(end_pos + 1);

                    outfile << "     " << var_name << " = " << to_output << ";\n";
                }
                else {
                    cerr << "ERROR CODE 1: Invalid declaration of string variable." << endl;
                    return 1;
                }
            }
            else if ((pos = line.find("input")) != string::npos) {
                line.erase(pos, 5);

                size_t start_pos = line.find('+');
                size_t end_pos = line.find('+', start_pos + 1);

                if (start_pos != string::npos && end_pos != string::npos) {
                    string to_output = line.substr(start_pos + 1, end_pos - start_pos - 1);
                    line.erase(start_pos, end_pos - start_pos + 1);

                    outfile << "    getline(cin, " << to_output << ");";
                    outfile << to_output << " = to_lower(" << to_output << ");";
                }
                else {
                    start_pos = line.find('+');
                    end_pos = line.find('+', start_pos + 1);

                    if (start_pos != string::npos && end_pos != string::npos) {
                        string to_output = line.substr(start_pos + 1, end_pos - start_pos - 1);
                        line.erase(start_pos, end_pos - start_pos + 1);

                        outfile << "    cout << " << to_output << ";";
                    }
                }
            }
            else if ((pos = line.find("if")) != string::npos) {
                line.erase(pos, 2);

                size_t start_pos = line.find('$');
                size_t end_pos = line.find('$', start_pos + 1);

                if (start_pos != string::npos && end_pos != string::npos) {
                    string var_name = line.substr(start_pos + 1, end_pos - start_pos - 1);
                    string condition = line.substr(end_pos + 1);

                    condition.erase(remove_if(condition.begin(), condition.end(), ::isspace), condition.end());

                    outfile << "if (" << var_name << condition << ") {";
                    cout << "if (" << var_name << " == " << condition << ") {";
                }
                else {
                    cerr << "ERROR: Invalid declaration of conditional statement." << endl;
                    return 1;
                }
            }
            else if ((pos = line.find("while")) != string::npos) {
                line.erase(pos, 5);

                size_t start_pos = line.find('$');
                size_t end_pos = line.find('$', start_pos + 1);

                if (start_pos != string::npos && end_pos != string::npos) {
                    string var_name = line.substr(start_pos + 1, end_pos - start_pos - 1);
                    string condition = line.substr(end_pos + 1);

                    condition.erase(remove_if(condition.begin(), condition.end(), ::isspace), condition.end());

                    outfile << "while (" << var_name << condition << ") {";
                    cout << "while (" << var_name << " == " << condition << ") {";
                }
                else {
                    cerr << "ERROR: Invalid declaration of conditional statement." << endl;
                    return 1;
                }
            }
            else if (line.find("end") != string::npos) {
                outfile << "}";
            }
            else if (line.find("debug") != string::npos) {
                debug = true;
            }
            else if (line.find("clear") != string::npos) {
                outfile << "        system(\"cls\");";
            }
            else if (line.find("exit") != string::npos) {
                outfile << "        break;";
            }
            else if (line.find("return") != string::npos) {
                outfile << "        return;";
            }
            else if ((pos = line.find("inputint")) != string::npos) {
                line.erase(pos, 8);

                size_t start_pos = line.find('+');
                size_t end_pos = line.find('+', start_pos + 1);

                if (start_pos != string::npos && end_pos != string::npos) {
                    string to_output = line.substr(start_pos + 1, end_pos - start_pos - 1);
                    line.erase(start_pos, end_pos - start_pos + 1);

                    outfile << "    getline(cin, intbuffer);\n" << to_output << "= stoi(intbuffer);\n";  //todo fix stoi call
                    outfile << to_output << " = to_lower(" << to_output << ");";
                }
                else {
                    start_pos = line.find('+');
                    end_pos = line.find('+', start_pos + 1);

                    if (start_pos != string::npos && end_pos != string::npos) {
                        string to_output = line.substr(start_pos + 1, end_pos - start_pos - 1);
                        line.erase(start_pos, end_pos - start_pos + 1);

                        outfile << "    cout << " << to_output << ";";
                    }
                }
            }
            else if ((pos = line.find("math")) != string::npos) {
                line.erase(pos, 5);

                size_t start_pos = line.find('$');
                size_t end_pos = line.find('$', start_pos + 1);

                if (start_pos != string::npos && end_pos != string::npos) {
                    string to_output = line.substr(start_pos + 1, end_pos - start_pos - 1);
                    line.erase(start_pos, end_pos - start_pos + 1);

                    outfile << to_output << ";";
                }
            }
        }

        outfile << "\n    cin.get();\n    return 0;\n}\n";
        myfile.close();
    }
    else {
        cerr << "Unable to open file." << endl;
        return 1;
    }

    outfile.close();

    cout << "Text has been written to the file successfully." << endl;

    int compile_result = system("g++ -o output output.cpp ");




    if (compile_result != 0) {
        cerr << "Compilation failed!" << endl;
        cin.get();
        return 1;
    }
    if (!debug) {
        remove("output.cpp");
    }
    cout << "Executable file has been generated successfully." << endl;
    cin.get();

    return 0;
}
