#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);

	ofEnableDepthTest();
	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {

	this->noise_step += 0.008;
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	int width = 350;
	int height = 350;
	int len = 30;
	for (int z = -300; z <= 1200; z += 30) {

		ofPushMatrix();
		ofTranslate(0, 0, z);
		ofRotate(ofMap(ofNoise((z + 300) * 0.001 + this->noise_step), 0, 1, -360, 360));

		ofFill();
		ofSetColor(39);

		ofBeginShape();

		ofVertex(glm::vec2(width * -1.0, height * -0.5));
		ofVertex(glm::vec2(width * 1.0, height * -0.5));
		ofVertex(glm::vec2(width * 1.0, height * 0.5));
		ofVertex(glm::vec2(width * -1.0, height * 0.5));

		ofNextContour(true);

		ofVertex(glm::vec2(width * -1.0 + len, height * -0.5 + len));
		ofVertex(glm::vec2(width * 1.0 - len, height * -0.5 + len));
		ofVertex(glm::vec2(width * 1.0 - len, height * 0.5 - len));
		ofVertex(glm::vec2(width * -1.0 + len, height * 0.5 - len));

		ofEndShape(true);

		ofNoFill();
		ofSetColor(239, ofMap(z, -300, 1200, 0, 255));

		ofBeginShape();

		ofVertex(glm::vec2(width * -1.0, height * -0.5));
		ofVertex(glm::vec2(width * 1.0, height * -0.5));
		ofVertex(glm::vec2(width * 1.0, height * 0.5));
		ofVertex(glm::vec2(width * -1.0, height * 0.5));

		ofNextContour(true);

		ofVertex(glm::vec2(width * -1.0 + len, height * -0.5 + len));
		ofVertex(glm::vec2(width * 1.0 - len, height * -0.5 + len));
		ofVertex(glm::vec2(width * 1.0 - len, height * 0.5 - len));
		ofVertex(glm::vec2(width * -1.0 + len, height * 0.5 - len));

		ofEndShape(true);

		ofPopMatrix();
	}

	this->cam.end();

	/*
	int start = 160;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}