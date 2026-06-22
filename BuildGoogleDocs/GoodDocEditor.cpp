#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DocumentElement{
    public:
        virtual string render()=0; // pure virtual function
};

class TextElement : public DocumentElement{
    private:
        string text;
    public:
        TextElement(string text){
            this->text=text;
        }
        string render() override{
            return text;
        }
}; 

class ImageElement : public DocumentElement{
    private:
        string imagePath;
    public:
        ImageElement(string path){
            this->imagePath=path;
        }
        string render() override{
            return "[Image: " + imagePath + "]";
        }
};

class NewlineElement : public DocumentElement{
    public:
        string render() override{
            return "\n";
        }
};

class TabSpaceElement : public DocumentElement{
    public:
        string render() override{
            return "\t";
        }
};

class Document{
    private:
        vector<DocumentElement*> elements;
    public:
        void addElement(DocumentElement* element){
            elements.push_back(element);
        }
        string render(){
            string result;
            for(auto element : elements){
                result += element->render();
            }
            return result;
        }
};

class Persistence{
    public:
        virtual void save(string data)=0; // pure virtual function
};

class FileStorage : public Persistence{
    public:
        void save(string data) override{
            ofstream outFile("document2.txt");
            if(outFile.is_open()){
                outFile << data;
                outFile.close();
                cout << "Document saved to document.txt" << endl;
            } else {
                cout << "Error saving document!" << endl;
            }
        }
};

class DBStorage : public Persistence{
    public:
        void save(string data) override{
            // save to db
        }
};

class DocumentEditor{
    private:
        Document* document;
        Persistence* storage; 
        string renderedDocument;

    public:
    // any storage due to polymorphism
        DocumentEditor(Document* document, Persistence* storage){
            this->document=document;
            this->storage=storage;
        } 
        void addText(string text){
            document->addElement(new TextElement(text));
        }
        void addImage(string imagePath){
            document->addElement(new ImageElement(imagePath));
        }
        void addNewline(){
            document->addElement(new NewlineElement());
        }
        void addTabSpace(){
            document->addElement(new TabSpaceElement());
        }
        string renderDocument(){
            if(renderedDocument.empty()){
                renderedDocument = document->render();
            }
            return renderedDocument;
        }
        void saveDocument(){
            storage->save(renderDocument());
        }
};

int main(){
    Document* document=new Document();
    Persistence* persistence=new FileStorage();
    DocumentEditor* editor= new DocumentEditor(document, persistence);

    editor->addText("This is a sample document.");
    editor->addNewline();
    editor->addImage("image1.jpg");
    editor->addNewline();
    editor-> addTabSpace();
    editor->addText("This document contains text and images.");
    cout << editor->renderDocument() << endl;
    editor->saveDocument();
    return 0;
}