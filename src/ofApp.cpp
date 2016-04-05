#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundColor(0, 0, 0);
    //ofSetColor(0,0,0);
    
    ofSetFrameRate(10);
    
    font.load("Helvetica.dfont", 16);
    font2.load("Helvetica.dfont", 24);
    
    //ofDirectory dir(path);
    //dir.listDir();
    
    padTop = 60;
    padRight = 60;
    
    max = 436;
    
    curImg = 0;
    
    imgHeight = 700;
    
    // Load a CSV File.
    //csv.loadFile(ofToDataPath("captions.tsv"), "\t");
    sorting.loadFile(ofToDataPath("sorting.tsv"), "\t");
    
    curFile = 0;
    img.load("isolated_faces/" + sorting.data[curFile][1] + ".jpg");
    picID = sorting.data[curFile][0];
    picYear = sorting.data[curFile][2];
    picTitle = sorting.data[curFile][3];
                           
    //img.load(dir.getPath(curFile));
    
    int oldHeight = img.getHeight();
    img.resize((imgHeight/oldHeight)*img.getWidth()+((imgHeight%oldHeight)*img.getWidth())/oldHeight,imgHeight);
    
    /*
    picID = dir.getName(curFile);
    ofStringReplace(picID, "-1.jpg", "");
    ofStringReplace(picID, "-2.jpg", "");
    ofStringReplace(picID, "-3.jpg", "");
    ofStringReplace(picID, "-4.jpg", "");
    ofStringReplace(picID, "-5.jpg", "");
    ofStringReplace(picID, "-6.jpg", "");
    ofStringReplace(picID, "-7.jpg", "");
    ofStringReplace(picID, "-8.jpg", "");
    ofStringReplace(picID, "-9.jpg", "");
     */
    
    /*
    int i = 0;
    curStr = "";
    while(i < 31595){
        if(csv.data[i][0] == picID){
            curStr = csv.data[i][1];
            break;
        }
        i++;
    }
     */
    
    /*
    cout << "Print out a specific CSV value" << endl;
    cout << csv.data[0][1] << endl;
    // also you can write...
    //cout << csv.data[0].at(1) << endl;
    
    cout << "Print out the first value" << endl;
    cout << csv.data[0].front() << endl;
    
    cout << "Maximum Size:";
    cout << csv.data[0].max_size() << endl;
     */
    
    
/*
    //go through and print out all the paths
    for(int i = 0; i < dir.size(); i++){
        img.load(dir.getPath(i));
        
        finder.findHaarObjects(img);
        
        for(unsigned int j = 0; j < finder.blobs.size(); j++) {
            ofRectangle cur = finder.blobs[j].boundingRect;
            //ofDrawRectangle(cur.x, cur.y, cur.width, cur.height);
            cropped.cropFrom(img, cur.x, cur.y, cur.width, cur.height);
            //std::stringstream ss;
            //ss << "chkfaces/" << splitString[i].c_str() << "-";
            string newName = dir.getName(i);
            ofStringReplace(newName, ".jpg", "");
            cropped.save("allfaces/" + newName + "-" + to_string(j+1) + ".jpg");
        }
        
        ofLogNotice(dir.getPath(i));
    }
    
*/

    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    if(curFile == max){
        curFile = 0;
    } else {
        curFile ++;
    }
    
    ofLog(OF_LOG_NOTICE, to_string(curFile));
    
    img.load("isolated_faces/" + sorting.data[curFile][1] + ".jpg");
    picID = sorting.data[curFile][0];
    picYear = sorting.data[curFile][2];
    picTitle = sorting.data[curFile][3];
    
    int oldHeight = img.getHeight();
    img.resize((imgHeight/oldHeight)*img.getWidth()+((imgHeight%oldHeight)*img.getWidth())/oldHeight,imgHeight);
    
    
    /*
    ofDirectory dir(path);
    dir.listDir();

    img.load(dir.getPath(curFile));
    int oldHeight = img.getHeight();
    img.resize((imgHeight/oldHeight)*img.getWidth()+((imgHeight%oldHeight)*img.getWidth())/oldHeight,imgHeight);
    picID = dir.getName(curFile);
    ofStringReplace(picID, "-1.jpg", "");
    ofStringReplace(picID, "-2.jpg", "");
    ofStringReplace(picID, "-3.jpg", "");
    ofStringReplace(picID, "-4.jpg", "");
    ofStringReplace(picID, "-5.jpg", "");
    ofStringReplace(picID, "-6.jpg", "");
    ofStringReplace(picID, "-7.jpg", "");
    ofStringReplace(picID, "-8.jpg", "");
    ofStringReplace(picID, "-9.jpg", "");
     
    int i = 0;
    curStr = "";
    while(i < 31595){
        if(csv.data[i][0] == picID){
            curStr = csv.data[i][1];
            break;
        }
        i++;
    }
     */
    
    
    img.draw(padRight, padTop);
    
    //ofFill();
    font.drawString(picYear, padRight, img.getHeight()+40+padTop);
    font2.drawString(picTitle, padRight, img.getHeight()+90+padTop);
    
    //ofNoFill();
    /*
    for(unsigned int i = 0; i < finder.blobs.size(); i++) {
        ofRectangle cur = finder.blobs[i].boundingRect;
        ofDrawRectangle(cur.x, cur.y, cur.width, cur.height);
    }
     */
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //352 = right
    //356 = left
    
    /*
    bool change = false;
    
    
    if(key == 358){
        if(curFile == max){
            curFile = 0;
            change = true;
        } else {
           curFile ++;
           change = true;
        }

    } else if(key == 356){
        if(curFile == 0){
            curFile = max;
            change = true;
        } else {
            curFile--;
            change = true;
        }
    }
   // ofLog(OF_LOG_NOTICE, to_string(key));
    

    if(change){
        
        ofDirectory dir(path);
        dir.listDir();
        
        
        img.load(dir.getPath(curFile));
        int oldHeight = img.getHeight();
        img.resize((imgHeight/oldHeight)*img.getWidth()+((imgHeight%oldHeight)*img.getWidth())/oldHeight,imgHeight);
        picID = dir.getName(curFile);
        ofStringReplace(picID, "-1.jpg", "");
        ofStringReplace(picID, "-2.jpg", "");
        ofStringReplace(picID, "-3.jpg", "");
        ofStringReplace(picID, "-4.jpg", "");
        ofStringReplace(picID, "-5.jpg", "");
        ofStringReplace(picID, "-6.jpg", "");
        ofStringReplace(picID, "-7.jpg", "");
        ofStringReplace(picID, "-8.jpg", "");
        ofStringReplace(picID, "-9.jpg", "");
        
        
        int i = 0;
        curStr = "";
        while(i < 31595){
            if(csv.data[i][0] == picID){
                curStr = csv.data[i][1];
                break;
            }
            i++;
        }

        
    }
    
     */
     
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
