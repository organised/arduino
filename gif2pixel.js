// Takes a gif and places every single frame into a comma delimited line of RGB values, useful for translating animation to LED etc. 

let gif;
let pixels = [];

function preload() {
  gif = loadImage('animated.gif');
}

function setup() {
  createCanvas(gif.width, gif.height);
  processFrames();
}

function processFrames() {
  // Get the total number of frames in the GIF
  let numFrames = gif.numFrames();

  // Process each frame sequentially
  let frameIndex = 0;
  processFrame(frameIndex, numFrames);
}

function processFrame(frameIndex, numFrames) {
  // Set the current frame
  gif.setFrame(frameIndex);

  // Wait for the frame to be loaded
  setTimeout(() => {
    // Load the pixels for the current frame
    gif.loadPixels();

    // Iterate over each pixel row
    for (let y = 0; y < gif.height; y++) {
      let rowPixels = [];
      // Iterate over each pixel in the row
      for (let x = 0; x < gif.width; x++) {
        let index = (x + y * gif.width) * 4;
        let r = gif.pixels[index];
        let g = gif.pixels[index + 1];
        let b = gif.pixels[index + 2];
        rowPixels.push(`${r},${g},${b}`);
      }
      pixels.push(rowPixels.join(','));
    }

    // Print the comma-delimited RGB values as a string for the current frame
    //console.log(`Frame ${frameIndex + 1}:`);
    console.log(pixels.join('\n'));

    // Clear the pixels array for the next frame
    pixels = [];

    // Process the next frame
    frameIndex++;
    if (frameIndex < numFrames) {
      processFrame(frameIndex, numFrames);
    }
  }, 0);
}
