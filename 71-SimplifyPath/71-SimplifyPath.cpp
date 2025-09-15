// Last updated: 9/16/2025, 12:09:45 AM
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;     // Acts like stack to store valid path parts
        stringstream ss(path);    // Used to split the input path by '/'
        string part;              // To store each part between slashes

        while (getline(ss, part, '/')) {     // Read each part between '/'
            if (part == "" || part == ".") {
                continue;                    // Skip empty or current directory parts
            } else if (part == "..") {
                if (!stack.empty()) stack.pop_back(); // '..' means go one directory up
            } else {
                stack.push_back(part);       // Valid directory name, add to the stack
            }
        }
        string result = "/";
        for (int i = 0; i < stack.size(); ++i) {
            result += stack[i];              // Add each directory part
            if (i != stack.size() - 1) result += "/";
        }

        return result;   
    }
};