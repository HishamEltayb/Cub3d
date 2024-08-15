<h1 align="center">
   CUB3D      
</h2>
   <h2 align="center">
      (RayCasting with miniLibX)
</h2>

<h1 align="center">
   
   ![3e5f962b44c632a819141d61fd8558b55a0d07cc](https://github.com/user-attachments/assets/3e449db1-41a6-47b1-8dff-635829a981c9)
</h1>

<p align="center">
  <a href="#-about-the-project">About the project</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#-technologies">Technologies</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#-getting-started">Getting started</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#-how-to-contribute">How to contribute</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="LICENSE">License</a>
</p>

## 👨🏻‍💻 About the project
This project is inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to make a dynamic view inside a maze, in which you’ll have to find your way.</p>

<h1 align="center">
   
<img width="2096" alt="Screen Shot 2024-08-15 at 1 21 32 PM" src="https://github.com/user-attachments/assets/eb6efbc6-04ea-4bdd-bd78-d86b36169c93">

</h1>

## Introduction
- <p style="color: red;">The idea behind ray casting is to trace rays from the eye, one per pixel, and find the closest object blocking the path of that ray – think of an image as a screen-door, with each square in the screen being a pixel. This is then the object the eye sees through that pixel.</p>


### 🔍 Importance of Ray-Casting:

* <p style="color: red;">Understanding the basics of 3D rendering and graphics.
* <p style="color: red;">Learning about the intersection of rays and objects in 3D space.
* <p style="color: red;">Developing problem-solving skills in a graphical context.

### 💡Implemetation:
The system integrates multiple components to ensure a seamless and interactive 3D rendering process:

- **Ray-Casting Algorithm**: Implemented in C, handling the core logic of tracing rays and detecting intersections with objects.

- **3D Rendering**: Utilizing the MiniLibX library for rendering the 3D environment.

#### Rendering Process:

1. **Initialization:**
     Setting up the 3D environment and initializing the ray-casting algorithm.

2. **Ray-Casting:**
     Tracing rays from the eye, one per pixel, and detecting intersections with objects.

3. **Rendering:**
     Rendering the 3D environment based on the intersection points and object properties.

<h1 align="center">
   <img width="2528" alt="Screen Shot 2024-08-15 at 1 31 01 PM" src="https://github.com/user-attachments/assets/955120df-2c36-4429-99b1-a0b19b98763e">
</h1>

## 🚀 Technologies

Technologies used to develop Cub3D:
* [C Programming Language](https://en.wikipedia.org/wiki/C_(programming_language))
* [MiniLibX Library](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)
* [Ray-Casting Algorithm](https://en.wikipedia.org/wiki/Ray_casting#:~:text=Ray%20casting%20is%20the%20most,scenes%20to%20two%2Ddimensional%20images.)


## 💻 Getting started

<h1 align="center">
   
![3](https://github.com/AhmedAlfahal/CompasX-Hackathon/assets/122282675/40713ad6-4e86-4031-9749-5519ba734588)

   
</h1>

### Prerequisites

- **Node.js** and **npm**: Ensure you have Node.js and npm installed.
- **React.js**: Ensure you have React.js installed and all it's prerequests.
- **Metamask**: Install the Metamask extension for your browser.
- **Solana Test Network**: Access to a test network like Red Hat for deploying smart contracts.
- **Make**: Ensure you have Make installed to use Makefile files.
- **Docker**: Ensure you have Docker install and all it's prerequests.
- **Google Chrome Browser**: Ensure you have Google Chrome Browser installed.

### Installation

**1. Clone the project and access the folder**

```bash
git clone https://github.com/AhmedAlfahal/CompasX-Hackathon.git && cd CompasX-Hackathon
```

**2. Use Makefile**
```bash
  $ make
```
![make](https://github.com/AhmedAlfahal/CompasX-Hackathon/assets/122282675/7900e3c8-90d8-404c-895b-a6ddd4aec8c6)

**3. Install Meta Mask Extention**
![install meta mask](https://github.com/AhmedAlfahal/CompasX-Hackathon/assets/122282675/b5032cc2-dfd5-4a87-8764-703f1f5a59c3)

**4. Adding the netowrk to the Meta Mask**

![adding the network (1)](https://github.com/AhmedAlfahal/CompasX-Hackathon/assets/122282675/12ef6a56-fb73-4ac8-b532-1de9adb71366)

**5. Setup the private key**
![setup the private key](https://github.com/AhmedAlfahal/CompasX-Hackathon/assets/122282675/7e6662e1-5531-40f1-ab6d-19ee4b34c886)

**6. Manage Extention**

![manage extenstion](https://github.com/AhmedAlfahal/CompasX-Hackathon/assets/122282675/fcdd7e97-cb67-4bcb-87db-2649cc8551f6)

## Trade-off: Integrating User Profiles with NFTs

### Enhanced User Engagement: 
   Linking user profiles with NFTs can significantly enhance user engagement by offering tangible rewards tied to voting participation.

### Personalization and Identity: 
   Users can personalize their profiles with unique NFTs, fostering a stronger sense of identity and ownership within the voting platform.

### Monetary Incentives: 
   NFTs associated with user profiles may possess monetary value, potentially incentivizing increased participation and voting activity as users seek to acquire valuable NFTs.


## 🤔 How to contribute

**Make a fork of this repository**

```bash
# Fork using GitHub official command line
# If you don't have the GitHub CLI, use the web site to do that.

$ gh repo fork AhmedAlfahal/CompasX-Hackathon
```

**Follow the steps below**


**Clone your fork**
```bash
$ git clone your-fork-url && cd CompasX-Hackathon
```

**Create a branch with your feature**
```bash
$ git checkout -b my-feature
```

**Make the commit with your changes**
```bash
$ git commit -m 'feat: My new feature
```

**Send the code to your remote branch**
```bash
$ git push origin my-feature
```

### License
   This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.











![6](https://github.com/user-attachments/assets/a8c770b8-946e-4c97-9161-a44b50ac97cc)






