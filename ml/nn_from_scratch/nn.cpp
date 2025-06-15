#include <bits/stdc++.h>
using namespace std;

int dot(vector<float>& veca, vector<float>& vecb){
    int out = 0;
    for(int a : veca){
        for(int b : vecb){
            out += a*b;
        }
    }
    return out;
}

vector<float> scalar_to_vec(int s, int len){
    vector<float> v(len);
    for(int i = 0; i < len; i++){
        v[i] = s;
    }
    return v;
}

float mystery_func_a(float a, float b){
    return pow(a,2) + b;
}
float mystery_func_b(float a, float b){
    return pow(b,2) + 2*a;
}

vector<float> features_to_labels(float a, float b){
    return {mystery_func_a(a,b),mystery_func_b(a,b)};
}
vector<float> features_to_labels(vector<float>& features){
    return {mystery_func_a(features[0],features[1]),mystery_func_b(features[0],features[1])};
}

// TODO: generate features and labels from the above mystery funcs

int main(){
    // Create a random number generator seeded with a random device
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distr(0, 1);
    std::uniform_real_distribution<> feature_distr_train_1(0, 10);
    std::uniform_real_distribution<> feature_distr_test(11, 25);
    std::uniform_real_distribution<> feature_distr_train_2(26, 40);

    float learning_rate = 0.0001;
    float random_number = distr(gen);

    float a = feature_distr_train_1(gen), b = feature_distr_train_1(gen);
    vector<float> features = {a,b};
    vector<float> labels = features_to_labels(features);

    vector<float> hlw1(4);
    vector<float> hlb1(4);

    vector<float> hlw2(4);
    vector<float> hlb2(4);

    vector<float> outputw(2);
    vector<float> outputb(2);

    for(int i = 0; i < hlw1.size(); i++){
        hlw1[i] = distr(gen);
        hlb1[i] = distr(gen);
    }
    for(int i = 0; i < hlw2.size(); i++){
        hlw2[i] = distr(gen);
        hlb2[i] = distr(gen);
    }
    for(int i = 0; i < outputw.size(); i++){
        outputw[i] = distr(gen);
        outputb[i] = distr(gen);
    }

    vector<float>* invec = &features;
    vector<float>* outvec = &hlw1;
    vector<float>* outvecb = &hlb1;

    // manual forward pass
    vector<float> hl1out(outvec->size());
    for(int i = 0; i < outvec->size(); i++){
        vector<float> weights = scalar_to_vec((*outvec)[i],outvec->size()); // scalar, length
        hl1out[i] = max(0.0f,dot(*invec, weights)+ (*outvecb)[i]); // relu applied
    }

    invec = &hl1out;
    outvec = &hlw2;
    outvecb = &hlb2;

    // manual forward pass
    vector<float> hl2out(outvec->size());
    for(int i = 0; i < outvec->size(); i++){
        vector<float> weights = scalar_to_vec((*outvec)[i],outvec->size()); // scalar, length
        hl2out[i] = max(0.0f,dot(*invec, weights)+ (*outvecb)[i]); // relu applied
    }

    invec = &hl2out;
    outvec = &outputw;
    outvecb = &outputb;

    // manual forward pass
    vector<float> predicted(outvec->size());
    for(int i = 0; i < outvec->size(); i++){
        vector<float> weights = scalar_to_vec((*outvec)[i],outvec->size()); // scalar, length
        predicted[i] = max(0.0f,dot(*invec, weights)+ (*outvecb)[i]); // relu applied
    }

    // compute loss
    float loss = 0;
    for(int i = 0; i < labels.size(); i++){ // labels and predicted should be the same length
        loss += pow(predicted[i]-labels[i],2);
    }
    loss = loss / labels.size();

    // then do backpropagation

    //relu derivative: 1 if greater than 0, else 0
    // (x*w+b)*relu_derivative
    // d wrt b: 1*relu_derivative
    // d wrt w: x*relu_derivative
    //
    //
    // subtract the gradient times a learning_rate to minimize loss

    for(int i = 0; i < outputb; i++){
        outputb[i] -= ???
    }

    cout << "Features: ";
    for(int i = 0; i < features.size(); i++){
        cout << features[i] << (i != features.size() - 1 ? ", " : "");
    }
    cout << endl;
    cout << "Labels: ";
    for(int i = 0; i < labels.size(); i++){
        cout << labels[i] << (i != labels.size() - 1 ? ", " : "");
    }
    cout << endl;
    cout << "Predicted: ";
    for(int i = 0; i < predicted.size(); i++){
        cout << predicted[i] << (i != predicted.size() - 1 ? ", " : "");
    }
    cout << endl;
    cout << "Loss: " << loss << endl;
    // then loss

}
