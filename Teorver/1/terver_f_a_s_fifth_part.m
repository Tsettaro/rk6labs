% Enter here
R1 = 9; G1 = 7; B1 = 8; sum = R1 + G1 + B1;

% LET'S PARTY
p = R1/sum; q = 1-p; n = 1000;

% Task №1.7
n = sum;
x_2 = (n-n*p)/sqrt(n*p*q);
phi_x_2 = 0.5;
p_k = [0.7 0.8 0.9 0.95 0.99];
phi_x_1 = zeros(1, length(p_k));
for i=1:length(p_k)
    phi_x_1(i) = phi_x_2 - p_k(i);
end

syms n;
n_arr = [];
for j = [0.52 0.84 1.28 1.65 2.34]
    temp = round(double(vpasolve((n*p - sum)/sqrt(sum * p * q) == j, n)));
    n_arr = [n_arr temp];
end

figure(1);
scatter(p_k, n_arr, "blue", "filled"), title("P(k)"), xlabel("P(k)"), ylabel("n");
grid on;