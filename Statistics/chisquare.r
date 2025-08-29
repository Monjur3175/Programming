# Parameters
K <- 5          # degrees of freedom
N_sim <- 1000   # number of simulations

# Set seed for reproducibility
set.seed(123)

# Generate chi-square data
chi_data <- rchisq(N_sim, df = K)

# Compute mean and variance
mean_chi <- mean(chi_data)
var_chi <- var(chi_data)

print(paste("Mean:", mean_chi))
print(paste("Variance:", var_chi))
print(paste("Theoretical Mean:", K))
print(paste("Theoretical Variance:", 2*K))

# Graphical output
par(mfrow = c(1, 3))  # 3 plots side by side

# 1. Histogram with theoretical curve
hist(chi_data, breaks = 30, col = "lightblue", probability = TRUE,
     main = "Chi-squared Distribution",
     xlab = "Value", border = "white")
curve(dchisq(x, df = K), add = TRUE, col = "red", lwd = 2)

# 2. Density plot
plot(density(chi_data), col = "blue", lwd = 2,
     main = "Density of Simulated Chi-squared",
     xlab = "Value")
curve(dchisq(x, df = K), col = "red", lwd = 2, add = TRUE)
legend("topright", legend = c("Simulated Density", "Theoretical Density"),
       col = c("blue", "red"), lwd = 2, bty = "n")

# 3. Q-Q plot
qqplot(qchisq(ppoints(N_sim), df = K), chi_data,
       main = "Q-Q Plot for Chi-squared Data",
       col = "blue", xlab = "Theoretical Quantiles",
       ylab = "Sample Quantiles")
abline(0, 1, col = "red", lwd = 2)
