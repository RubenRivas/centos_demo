#include <iostream>
#include "split_log.h"
using namespace std;

int main() {
    string text = "INFO  - 2023-07-24 18:46:15.870; "
                  "org.apache.solr.core.SolrCore; "
                  "After->1690238773649:[collection1] "
                  "webapp=/solr path=/select "
                  "params={q=*:*&wt=json&shards.tolerant=true&rows=0} "
                  "hits=164517507 status=0 QTime=2221";
    split_log(text.begin(), text.end(), [](auto key, auto token) {
        cout << key << ": " << token << endl;
    });
	return 0;
}
