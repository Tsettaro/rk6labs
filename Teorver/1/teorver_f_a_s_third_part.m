% Enter here
R1 = 9; G1 = 7; B1 = 8; sum = R1 + G1 + B1;

% LET'S PARTY
p = R1/sum; q = 1 - p;

% Task 1.4
x = [];
temp = [25 50 100 200 400];
for n = temp
    k = R1/sqrt(n * p * q);
    x = [x k];
end
phi = 2.*[0.4999 0.4956 0.4686 0.4049 0.3238]; %phi узнавайте сами
figure(1);
scatter(temp, phi,'filled','blue'), title("P"), xlabel("n"), ylabel("P(x)");
grid on;

% Task 1.5
n = 1000;
temp = [0.1 0.01 0.001]; x = [];
for i = temp
    k = (i*sqrt(n))/sqrt(p * q);
    x = [x k];
end
phi = 2.*[0.5 0.2422 0.0279]; %phi подбирать самому
figure(2);
scatter(temp,phi,'filled','blue'), title("P"), xlabel("n"), ylabel("P(x)");
grid on;
