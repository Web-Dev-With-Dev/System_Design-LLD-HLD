#include<bits/stdc++.h>
using namespace std;

class IReport {
    public:
        virtual string getJsonData(const string& Data) = 0;
        virtual ~IReport() {}
};

class XmlDataProvider {
    public:

    string getXmlData(const string& data) {
        size_t sep = data.find(':');
        string name = data.substr(0,sep);
        string id = data.substr(sep+1);

        return  "<user>"
                "<name>" + name + "</name>"
                "<id>" + id + "</id>"
                "</user>";
    }
};

class XmlDataProviderAdapter : public IReport {
    private:
        XmlDataProvider* xmlProvider;
    
    public:
        XmlDataProviderAdapter(XmlDataProvider* provider){
            this->xmlProvider = provider;
        }

        string getJsonData(const string& data) override {
            string xml = xmlProvider->getXmlData(data);

            size_t startName = xml.find("<name>") + 6;
            size_t endName = xml.find("</name>");
            string name = xml.substr(startName , endName - startName);

            size_t startId = xml.find("<id>") + 4;
            size_t endId = xml.find("</id>");
            string id = xml.substr(startId , endId - startId);

            return "{\"name\" : \"" + name + "\" , \"id\" : \"" + id + "\"}";
        }
};

class Client {

    public:
        void getReport(IReport* report , string rawData){
            cout<<"processed Json : "
            << report->getJsonData(rawData)
            <<endl;
        }
};

int main()
{
    XmlDataProvider* xmlProvider = new XmlDataProvider();

    IReport* adapter = new XmlDataProviderAdapter(xmlProvider);

    string rawData = "Dev:43";

    Client* client = new Client();

    client->getReport(adapter , rawData);

    delete adapter;
    delete xmlProvider;

    return 0;
}
