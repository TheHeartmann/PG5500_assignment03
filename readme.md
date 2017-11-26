# PG5500 Embedded Systems: assignment 3: Harticle Photom News Nibbles

## Product description (or 'what is it?')

The Harticle Photom News Nibbles is a small device that connects to a news API and fetches the top headlines from a specified set of sources. It then displays these in a slideshow fashion on the screen, along with information on whom the source is, whom the author is, and when it was posted.

## Use case (or '... and _why_ do I need this?')

Ever fallen completely out of touch with the world without the time to catch up? Ever thought you were just going to quickly check the news but ended up spending hours after 'accidentally' opening social media or finding a trail of interesting articles? Ever wanted but a quick, superficial glance at the latest movement in the world?

Based completely on anecdotal evidence, I am fairly certain that at these apply to more people than just myself. Sometimes it's nice to just have a quick survey of what's going on, and I know that if I whip out my phone to start browsing, a lot of time passes very quickly. So if you're strapped for time you can read some headlines while munching down your toast, or while you're having that last cup of tea before going to bed. _That's_ what this device is for. Those little moments.

## Instructions (or 'how do I ...?')

Assuming that you have set up your Photon (see [this guide](https://docs.particle.io/guide/getting-started/start/photon/) for a quick and easy tutorial if you have not), it should be as simple as setting up the webhook and compiling and flashing the device. The API key is hardcoded into the `Settings.h` file, so you needn't worry about that unless you want to.

To set up the webhook, I recommend installing the Particle CLI (see [this guide](https://docs.particle.io/guide/tools-and-features/cli/photon/) for instructions), after which you should be able to run the command
```
$ particle webhook create [path/to/webhook.json]
```
which will take care of the rest for you. So, assuming you're currently in the root of the project, the exact command would be
```
$ particle webhook create webhooks/headlines.json
```

The compilation can be triggered either via the Particle CLI or via the [cloud IDE](https://build.particle.io/build) and can happen either locally or in the cloud. Personally I have been building this in the cloud all along.

## Functionality

The Harticle Photom News Nibbles is a fairly simple device. On startup it sends a request to News API, asking for the top headlines from the selected news sources, and then displays them on the screen one at a time. This repeats itself every five minutes.

The device can be interfaced with through the Particle CLI or the online Particle Console: Sources and languages can be extracted, sources can be set, and the particle can be forced to update.

The available function calls are:

```
int set_source_1(String source)
int set_source_2(String source)
int set_language(String language)
int update(String _)
```
The two first take a string for a news provider to replace one of the current sources. The full list of available sources can be found at [this link](https://newsapi.org/sources), but please note that not all of them will be accepted by the device. A list of accepted providers can be found in `QueryManager.h`.

`set_language` takes a language string and filters articles based on said language from then on. Due to the limited number of sources available, the only valid language values are English ('en'), Norwegian ('no'), and an empty string (''), which removes filtering.

The `update` function triggers a re-fetch of the data. The string is ignored.

The available variables are:
```
source_1(string)
source_2(string)
language(string)
```

These variables return the currently active sources as well as the language parameter.

## Schematics

The schematics are drawn in Fritzing and are available in both Fritzing and SVG file formats.

The TFT screen in the schematics is not the exact same one as has been used, but the wiring corresponds to how it should be wired on an ST7735. For clarity, the connected pins are (in order top to bottom):

    - VCC
    - GND
    - SCL
    - SDA
    - DC
    - RES
    - CS

## Video documentation

The end product is documented in [this video](https://youtu.be/n6_GtWqN1b0).

## Code

The code is organised into subfolders under the `/lib` together with the external Adafruit library. Structuring it this way let me work more separated on various parts of the application and was very useful.

### Highlights

#### Inheritance and separation of concerns

Overall, I am fairly pleased with the standard of the code in terms of encapsulation, separation of concerns, inversion of control, etc.

While the whole DisplayElement hierarchy might seem a bit overkill for the simple way in which it was utilised, it was originally designed to support a lot more different screen and menu types--features that sadly had to be cut from the final version.

#### Naive JSON parser

While it is far from as complex as it could be, I am quite satisfied with the very naive JSON parser I created. I had some issues finding any external libraries for it at first, and especially libraries that could take strings in chunks that might not represent valid JSON data, so I created the very simple logic in `JsonParser.h` which let me accept strings as they arrived and shove them into the SparkJson objects when they were ready.

### Libraries

For this device, the following external libraries have been used:

#### [SparkJson](https://github.com/menan/SparkJson)

A modified version of the [ArduinoJson](http://arduinojson.org/) library which takes care of parsing and organising JSON data. Has been absolutely invaluable for this project.

#### [Adafruit_ST7735_mfGFX](https://github.com/pkourany/Adafruit_ST7735_mfGFX)

A modified version of the Adafruit ST_7735 GFX library, containinc some extra fonts. The extra functionality was sadly dropped at the last minute due to some symbols not rendering in certain fonts. Otherwise, this library has also been key in making the screen work as intended.

### Notes

#### Issues

##### SOS

Every now and again the device will panic with a 'hard fault' and reboot. The intervals are seemingly random and can vary from minutes to hours. When it does happen it will quickly restart and resume fetching and displaying results. Note, however, that any values changed at runtime will be reset.

##### Character rendering

There is an issue with rendering certain characters, such as apostrophes and m-dashes, which caused me to have to give up on the custom fonts as they would simply stop the rendering process. The default font displays these as a jumbled mess, but at least it renders fine. What's more, these strings render perfectly fine through the serial monitor, suggesting there is something off about the screen or my interfacing with it.

### Further development

#### Downscoping and the lost features

As with all other projects, there was no shortage of ideas about what to implement, but as time ran on and a lot of them had to be let go. Here is a list of some of the most sought after features that would likely be high on the list for further development:

- 'Next' and 'previous' buttons.
- Support for more sources and more data
- Support for additional filters
- The News API `/everything` database
- Startup screen
- Startup animation and 'fetching data' icons
- Support for multiple categories, each with their own news sources, search keys, etc.

## Authors

Thomas Hartmann
