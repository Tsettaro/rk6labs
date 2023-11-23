% Enter here
R1 = 9; G1 = 7; B1 = 8; sum = R1 + G1 + B1;

% LET'S PARTY
p = R1/sum; q = 1-p; n = 1000;

% Task №1.6
phi = [0.7 0.8 0.9 0.95 0.99]./2;
x = [1.04 1.29 1.65 1.96 2.58];
M = n * p;
k = sqrt(n * p * q) .*x;
less_k = zeros(1, length(x));
more_k = less_k;
for i=1:5
    less_k(i) = M - k(i);
    more_k(i) = M + k(i);
end


