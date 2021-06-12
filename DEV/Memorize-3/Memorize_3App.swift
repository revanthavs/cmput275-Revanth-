//
//  Memorize_3App.swift
//  Memorize-3
//
//  Created by Revanth_Avs on 18/05/21.
//

import SwiftUI

@main
struct Memorize_3App: App {
    var body: some Scene {
        WindowGroup {
//            let game = EmojiMemoryGame()
//            _ = ContentView(viewModel: game)
            EmojiMemoryGameView(viewModel: EmojiMemoryGame())
        }
    }
}
