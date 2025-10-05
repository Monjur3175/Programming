# Parameters
mu0 <- 5      # Null hypothesis mean
mu1 <- 6      # Alternative hypothesis mean
sigma <- 2    # Population standard deviation
n <- 30       # Sample size
alpha <- 0.05 # Significance level

# Generate sample data
set.seed(123)
sample_data_H0 <- rnorm(n, mean = mu0, sd = sigma)  # Data under H0
sample_data_H1 <- rnorm(n, mean = mu1, sd = sigma)  # Data under H1

# Likelihood ratio test function
likelihood_ratio <- function(data, mu0, mu1, sigma) {
  exp(sum(dnorm(data, mean = mu1, sd = sigma, log = TRUE)) -
      sum(dnorm(data, mean = mu0, sd = sigma, log = TRUE)))
}

# Compute likelihood ratio for both samples
LR_H0 <- likelihood_ratio(sample_data_H0, mu0, mu1, sigma)
LR_H1 <- likelihood_ratio(sample_data_H1, mu0, mu1, sigma)

# Critical value for test of mean
critical_value <- qnorm(1 - alpha, mean = mu0, sd = sigma / sqrt(n))

# Decisions based on sample means
decision_H0 <- mean(sample_data_H0) > critical_value
decision_H1 <- mean(sample_data_H1) > critical_value

# Output
cat("Critical Value:", round(critical_value, 4), "\n")
cat("Likelihood Ratio (H0):", round(LR_H0, 4), "\n")
cat("Likelihood Ratio (H1):", round(LR_H1, 4), "\n")
cat("Decision under H0 (Reject H0?):", decision_H0, "\n")
cat("Decision under H1 (Reject H0?):", decision_H1, "\n")

# Graphical Output
par(mfrow = c(1, 2))

# Density plot under H0
plot(density(sample_data_H0), col = "blue", lwd = 2,
     main = "Density under H0", xlab = "Sample Value")
abline(v = critical_value, col = "red", lty = 2, lwd = 2)
legend("topright", legend = c("Density (H0)", "Critical Value"),
       col = c("blue", "red"), lty = c(1, 2), cex = 0.8)

# Density plot under H1
plot(density(sample_data_H1), col = "green", lwd = 2,
     main = "Density under H1", xlab = "Sample Value")
abline(v = critical_value, col = "red", lty = 2, lwd = 2)
legend("topright", legend = c("Density (H1)", "Critical Value"),
       col = c("green", "red"), lty = c(1, 2), cex = 0.8)
