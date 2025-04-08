#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(25);
  ofSetWindowTitle("openframeworks");

  ofBackground(39);
  ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
  ofSetCircleResolution(72);
}

//--------------------------------------------------------------
void ofApp::update(){
  for (int i = this->location_list.size() - 1; i >= 0; i--) {

    if (this->radius_list[i] > 0) {

      this->radius_list[i] += this->speed_list[i] * 3;
    }
    else {

      this->radius_list[i] += this->speed_list[i] * 30;
    }

    if (this->radius_list[i] > this->max_radius_list[i]) {

      this->location_list.erase(this->location_list.begin() + i);
      this->radius_list.erase(this->radius_list.begin() + i);
      this->speed_list.erase(this->speed_list.begin() + i);
      this->max_radius_list.erase(this->max_radius_list.begin() + i);
      this->color_list.erase(this->color_list.begin() + i);
    }
  }

  ofColor color;
  for (int i = 0; i < 5; i++) {

    auto noise_location = glm::vec2(ofRandom(-400, 400), ofRandom(-400, 400));
    auto location = noise_location + glm::vec2(ofRandom(-30, 30), ofRandom(-30, 30));

    this->location_list.push_back(location);
    this->radius_list.push_back(ofRandom(-1200, -600));
    this->speed_list.push_back(ofRandom(0.3, 0.5));
    this->max_radius_list.push_back(ofRandom(15, 60));

    color.setHsb(ofRandom(255), 150, 255);
    this->color_list.push_back(color);
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  this->cam.begin();

  for (int i = 0; i < this->location_list.size(); i++) {

    if (this->radius_list[i] > 0) {

      auto alpha = this->radius_list[i] < this->max_radius_list[i] * 0.6 ? 255 : ofMap(this->radius_list[i], this->max_radius_list[i] * 0.6, this->max_radius_list[i], 255, 0);
      ofSetColor(this->color_list[i], alpha);

      ofNoFill();
      ofDrawCircle(this->location_list[i], this->radius_list[i]);

      ofFill();
      ofSetColor(this->color_list[i], alpha * 0.5);

      ofDrawCircle(this->location_list[i], this->radius_list[i]);

      if (this->radius_list[i] < 10) {
        ofDrawLine(glm::vec3(this->location_list[i], 0),
                   glm::vec3(this->location_list[i], this->radius_list[i] * 6 - 60));
      }
    }
    else {

      auto alpha = ofMap(this->radius_list[i], -1200, 0, 64, 255);
      ofSetColor(this->color_list[i], alpha);

      ofNoFill();
      ofDrawLine(glm::vec3(this->location_list[i], this->radius_list[i]),
                 glm::vec3(this->location_list[i], this->radius_list[i] - 60));
    }
  }

  this->cam.end();
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

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
