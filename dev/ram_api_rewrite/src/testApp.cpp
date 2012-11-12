#include "testApp.h"


const string myActorName = "Ando_2012-09-01_19-19-45";


//--------------------------------------------------------------
void testApp::setup()
{
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofBackground(0);
	oscReceiver.setup(10000);

	// enable ramBaseApp::setup, update, draw, exit
	ramEnableAllEvents();
}

//--------------------------------------------------------------
void testApp::update()
{
	while (oscReceiver.hasWaitingMessages())
	{
		ofxOscMessage m;
		oscReceiver.getNextMessage(&m);
		updateWithOscMessage(m);
	}
}

//--------------------------------------------------------------
void testApp::draw()
{
    ofEnableSmoothing();
	
	ramCameraBegin();
    
<<<<<<< HEAD
    cam.begin();

    // nodeFinder example 1
	vector<ramNode> nodes = nodeFinder.findNode(ramActor::JOINT_ADBOMEN);
	for (int i=0; i<nodes.size(); i++)
	{
		ramNode& node = nodes.at(i);
		
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		glPushMatrix();
		ofPushStyle();
		
		ofNoFill();
		ofSetLineWidth(3);
		ofSetHexColor(0x00DDFF);
		node.transformBegin();
		ofBox(120);
		node.transformEnd();
		
		ofPopStyle();
		glPopMatrix();
		glPopAttrib();
	}

    
    // nodeFinder example 2
	ramNode& node2 = nodeFinder.findNode(myActorName, ramActor::JOINT_HEAD);
//
//	glPushAttrib(GL_ALL_ATTRIB_BITS);
//	glPushMatrix();
//	ofPushStyle();
//
//	ofNoFill();
//	ofSetLineWidth(3);
//	ofSetHexColor(0xFF0000);
//	node2.transformBegin();
//	ofBox(100);
//	node2.transformEnd();
//
//	ofPopStyle();
//	glPopMatrix();
//	glPopAttrib();
    
    cam.end();
=======
    // nodeFinder example 1
    {
        vector<ramNode> nodes = nodeFinder.findNode(ramActor::JOINT_ADBOMEN);
        for (int i=0; i<nodes.size(); i++)
        {
            ramNode &node = nodes.at(i);
            
            glPushAttrib(GL_ALL_ATTRIB_BITS);
            glPushMatrix();
            ofPushStyle();
            
            ofNoFill();
            ofSetLineWidth(3);
            ofSetHexColor(0x00DDFF);
            node.transformBegin();
            ofBox(100);
            node.transformEnd();
            
            ofPopStyle();
            glPopMatrix();
            glPopAttrib();
        }
    }
    
    // nodeFinder example 2
    {
        ramNode &node = nodeFinder.findNode(myActorName, ramActor::JOINT_HEAD);
        
        glPushAttrib(GL_ALL_ATTRIB_BITS);
        glPushMatrix();
        ofPushStyle();

        ofNoFill();
        ofSetLineWidth(3);
        ofSetHexColor(0xFFDDFF);
        node.transformBegin();
        ofBox(100);
        node.transformEnd();

        ofPopStyle();
        glPopMatrix();
        glPopAttrib();
    }
>>>>>>> 30dd5af7d72eed1f1037b1b492a64b14afe8b07b
    
    ofDisableSmoothing();
	
	ramCameraEnd();
}


// ram methods
//--------------------------------------------------------------
void testApp::drawFloor()
{
    
}

// ram methods
//--------------------------------------------------------------
void testApp::drawActor(ramActor &actor)
{
    for (int i=0; i<actor.getNumNode(); i++)
    {
        ramNode &node = actor.getNode(i);
        
        {
            glPushAttrib(GL_ALL_ATTRIB_BITS);
            glPushMatrix();
            ofPushStyle();

            ofSetColor(255, 0, 0);
            ofNoFill();
            node.transformBegin();
            ofBox(10);
            node.transformEnd();

            ofSetColor(0, 255, 0);
            ofBox(node, 20);
            
            ofPopStyle();
            glPopMatrix();
            glPopAttrib();
        }
    
        
        if (node.hasParent())
        {
            ramNode *parent_node = node.getParent();
                
            glPushAttrib(GL_ALL_ATTRIB_BITS);
            glPushMatrix();
            ofPushStyle();
            
            ofSetColor(255);
            ofLine(node, *parent_node);
            
            ofPopStyle();
            glPopMatrix();
            glPopAttrib();
        }
    }
}

// ram methods
//--------------------------------------------------------------
void testApp::drawRigid(ramRigidBody &rigid)
{
    for (int i=0; i<rigid.getNumNode(); i++)
    {
        ramNode &node = rigid.getNode(i);

        {
            glPushAttrib(GL_ALL_ATTRIB_BITS);
            glPushMatrix();
            ofPushStyle();

            ofSetColor(255, 0, 0);
            ofNoFill();
            node.transformBegin();
            ofBox(10);
            node.transformEnd();

            ofSetColor(0, 255, 0);
            ofBox(node, 20);

            ofPopStyle();
            glPopMatrix();
            glPopAttrib();
        }
    }
}


void testApp::actorEntered(ramActor& actor)
{
	cout << __FUNCTION__ << ": " << actor.getName() << endl;
}

void testApp::actorExited(ramActor& actor)
{
	cout << __FUNCTION__ << ": " << actor.getName() << endl;
}

void testApp::rigidEntered(ramRigidBody& rigid)
{
	cout << __FUNCTION__ << ": " << rigid.getName() << endl;
}

void testApp::rigidExited(ramRigidBody& rigid)
{
	cout << __FUNCTION__ << ": " << rigid.getName() << endl;
}


//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y)
{
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg)
{
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo)
{

}