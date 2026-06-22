#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DocumentEditor{
    private:
        vector<string> docElements;
        string renderedDocument;

    public:
        void addText(string text){
            docElements.push_back(text);
        }
        void addImage(string imagePath){
            docElements.push_back(imagePath);
        }

        // renderdoc function is business logic absolutely.
        string renderDocument(){
            if(renderedDocument.empty()){
                string result;
                for(auto element : docElements){
                    if(element.size()>4 && (element.substr(element.size()-4) == ".jpg" 
                    || element.substr(element.size()-4) == ".png")){
                        result += "[Image: " + element + "]\n";
                    } else {
                        result += element + "\n";
                    }
                }
                renderedDocument = result;
            }
            return renderedDocument;
        }

        void saveToFile(){
            ofstream outFile("document1.txt");
            if(outFile.is_open()){
                outFile << renderDocument();
                outFile.close();
                cout << "Document saved to document.txt" << endl;
            } else {
                cout << "Error saving document!" << endl;
            }
        }
};

int main(){
    DocumentEditor editor;
    editor.addText("This is a sample document.");
    editor.addImage("image1.jpg");
    editor.addText("This document contains text and images.");
    
    cout << editor.renderDocument() << endl;
    editor.saveToFile();
    
    return 0;
}